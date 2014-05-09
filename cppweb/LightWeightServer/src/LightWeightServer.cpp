#include "LightWeightServer.h"
#include "DefaultRequestHandlerFactory.h"
#include "DefaultPage.h"

#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/LeakDetector.h"
#include "Poco/Thread.h"
#include <iostream>


using Poco::Net::ServerSocket;
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


void LightWeightServer::initialize(Application& self)
{
    loadConfiguration(); // load default configuration files, if present
    ServerApplication::initialize(self);
}


void LightWeightServer::uninitialize()
{
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
        unsigned short port = (unsigned short)config().getInt("HTTPTimeServer.port", 9980);

        // set-up a server socket
        ServerSocket svs(port);
        // set-up a HTTPServer instance
        DefaultRequestHandlerFactory* pFactory = new DefaultRequestHandlerFactory;
        HTTPServerParams* pParams = new HTTPServerParams;
        HTTPServer srv(pFactory, svs, pParams);

        _pServer = &srv;

        // start the HTTPServer
        srv.start();
        // wait for CTRL-C or kill
        waitForTerminationRequest();
        // Stop the HTTPServer
        srv.stopAll();
    }
//    Thread::sleep(10000);
    return Application::EXIT_OK;
}


int main(int argc, char** argv)
{
	LeakDetector leak;
    LightWeightServer app;
    return app.run(argc, argv);
}
