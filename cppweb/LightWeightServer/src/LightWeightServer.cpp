#include "PrecompiledHeaders.h"
#include "LightWeightServer.h"
#include "DefaultRequestHandlerFactory.h"
#include "CommonUtils.h"


using Poco::Net::ServerSocket;
using Poco::Net::SocketAddress;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPServerParams;
using Poco::Util::ServerApplication;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;
using Poco::LeakDetector;
using Poco::Thread;
using Poco::Timespan;
using Poco::Timer;
using Poco::TimerCallback;
using Poco::DateTime;
using Poco::DateTimeFormatter;
using std::string;
using namespace Poco::Data;


void LightWeightServer::initialize(Application& self)
{
    loadConfiguration(); // load default configuration files, if present
    ServerApplication::initialize(self);
    SQLite::Connector::registerConnector();
    createSessionPool(config());
    createThreadPool(config());
}


void LightWeightServer::uninitialize()
{
    destroyThreadPool();
    destroySessionPool();
    SQLite::Connector::unregisterConnector();
    ServerApplication::uninitialize();
}


void LightWeightServer::defineOptions(OptionSet& options)
{
    ServerApplication::defineOptions(options);

    options.addOption(
            Option("help", "h", "display help information on command line arguments")
            .required(false)
            .repeatable(false));
}


void LightWeightServer::handleOption(const std::string& name, const std::string& value)
{
    ServerApplication::handleOption(name, value);

    if (name == "help")
        _helpRequested = true;
}


void LightWeightServer::displayHelp()
{
    HelpFormatter helpFormatter(options());
    helpFormatter.setCommand(commandName());
    helpFormatter.setUsage("OPTIONS");
    helpFormatter.setHeader("A web server that serves the current date and time.");
    helpFormatter.format(std::cout);
}


int LightWeightServer::main(const std::vector<std::string>& args)
{
    if (_helpRequested)
    {
        displayHelp();
    }
    else
    {
        // get parameters from configuration file
        string host = config().getString("serversocket.host", "0.0.0.0");
        unsigned short port = (unsigned short)config().getInt("serversocket.port", 9980);
        int backlog = config().getInt("serversocket.backlog", 64);

        // set-up a server socket
        ServerSocket svs(SocketAddress(host, port), backlog);

        // set-up a HTTPServer instance
        DefaultRequestHandlerFactory* pFactory = new DefaultRequestHandlerFactory;
        HTTPServerParams* pParams = new HTTPServerParams;
        pParams->setThreadIdleTime(Timespan(config().getInt("tcpserver.threadIdleTimeSeconds"), 0));
        pParams->setMaxThreads(config().getInt("tcpserver.maxThreads"));
        pParams->setMaxQueued(config().getInt("tcpserver.maxQueued"));
        pParams->setTimeout(Timespan(config().getInt("httpserver.timeoutSeconds"), 0));
        pParams->setKeepAlive(config().getBool("httpserver.keepAlive"));
        pParams->setMaxKeepAliveRequests(config().getInt("httpserver.maxKeepAliveRequests"));
        pParams->setKeepAliveTimeout(Timespan(config().getInt("httpserver.keepAliveTimeoutSeconds"), 0));
        HTTPServer srv(pFactory, getThreadPool(), svs, pParams);
        _pServer = &srv;

        // start the HTTPServer
        srv.start();

        // start the timer
        Timer recordPerf(5000, 5000);
        recordPerf.start(TimerCallback<LightWeightServer>(*this, &LightWeightServer::onRecordPerformanceCounters));

        // wait for CTRL-C or kill
        waitForTerminationRequest();

        // stop the timer
        recordPerf.stop();

        // Stop the HTTPServer
        srv.stopAll();
    }
//    Thread::sleep(10000);
    return Application::EXIT_OK;
}


void LightWeightServer::onRecordPerformanceCounters(Timer& timer)
    /*
       CREATE TABLE PerformanceCounters (
            DateTime TEXT,
            ThreadPoolCapacity INTEGER,
            ThreadPoolUsed INTEGER,
            ThreadPoolAllocated INTEGER, 
            ThreadPoolAvailable INTEGER,
            ServerCurrentThreads INTEGER,
            ServerCurrentConnections INTEGER,
            ServerMaxQueued INTEGER,
            ServerQueuedConnections INTEGER,
            ServerTotalConnections INTEGER,
            ServerRefusedConnections INTEGER,
            ServerMaxConcurrentConnections INTEGER
       );

     */
{
    //poco_debug(logger(), "onRecordPerformanceCounters");

    DateTime current;

    Session db(getSession());
    db << "INSERT INTO PerformanceCounters VALUES (?,?,?,?,?,?,?,?,?,?,?,?)",
        use(DateTimeFormatter::format(current, "%Y-%m-%d %H:%M:%S.%i")), // TEXT as ISO8601 strings ("YYYY-MM-DD HH:MM:SS.SSS")
        use(getThreadPool().capacity()),
        use(getThreadPool().used()),
        use(getThreadPool().allocated()),
        use(getThreadPool().available()),
        use(server().currentThreads()),
        use(server().currentConnections()),
        use(server().params().getMaxQueued()),
        use(server().queuedConnections()),
        use(server().totalConnections()),
        use(server().refusedConnections()),
        use(server().maxConcurrentConnections()),
        now;

    // remove data one minute ago
    Timespan ago(0, 0, 1, 0, 0);

    db << "DELETE FROM PerformanceCounters WHERE DateTime < ?",
        use(DateTimeFormatter::format(current-ago, "%Y-%m-%d %H:%M:%S.%i")),
        now;
}


int main(int argc, char** argv)
{
    LeakDetector leak;
    LightWeightServer app;
    return app.run(argc, argv);
}
