#include "PrecompiledHeaders.h"
#include "CommonUtils.h"
#include "LightWeightServer.h"


using Poco::Util::AbstractConfiguration;
using Poco::Util::Application;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPServerRequest;
using Poco::URI;
using Poco::Timespan;
using Poco::DateTimeFormatter;
using std::string;
using namespace Poco::Data;


static SessionPool* pSessionPool = NULL;


bool hasSuffix(const string &str, const string &suffix)
{
    return str.size() >= suffix.size() &&
        str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}


bool IsEdit(const HTTPServerRequest& request)
{
    return hasSuffix(URI(request.getURI()).getPath(), "/edit");
}


bool IsNew(const HTTPServerRequest& request)
{
    return hasSuffix(URI(request.getURI()).getPath(), "/new");
}


bool IsShow(const HTTPServerRequest& request)
{
    return !IsEdit(request) && !IsNew(request);
}


string getId(const HTTPServerRequest& request)
{
    URI uri(request.getURI());
    const string& path = uri.getPath();

    if (IsNew(request)) {
        return "";
    }
    else if (IsEdit(request)) {
        size_t found = path.find_last_of('/', path.size()-6);
        return path.substr(found+1, path.size()-6-found);
    }
    else {
        size_t found = path.find_last_of('/');
        return path.substr(found+1);
    }
}


void getApplicationProperties(const string& base, StringMap& prop)
{
    AbstractConfiguration::Keys keys;
    AbstractConfiguration& config = Application::instance().config();
    config.keys(base, keys);
    if (keys.empty())
    {
        if (config.hasProperty(base))
        {
            prop[base] = config.getString(base);
        }
    }
    else
    {
        for (AbstractConfiguration::Keys::const_iterator it = keys.begin(); it != keys.end(); ++it)
        {
            string fullKey = base;
            if (!fullKey.empty()) fullKey += '.';
            fullKey.append(*it);
            getApplicationProperties(fullKey, prop);
        }
    }
}


void getRuntimeProperties(StringMap& prop)
{
    Timespan uptime = Application::instance().uptime();
    const LightWeightServer& serverApp = dynamic_cast<const LightWeightServer&>(Application::instance());
    const HTTPServer& server = serverApp.server();
    prop["runtime.uptime"] = DateTimeFormatter::format(uptime);
    prop["runtime.currentConnections"] = Poco::format("%d", server.currentConnections());
    prop["runtime.currentThreads"] = Poco::format("%d", server.currentThreads());
    prop["runtime.queuedConnections"] = Poco::format("%d", server.queuedConnections());
    prop["runtime.refusedConnections"] = Poco::format("%d", server.refusedConnections());
    prop["runtime.totalConnections"] = Poco::format("%d", server.totalConnections());
}


Session getSession()
{
    return pSessionPool->get();
}


void createSessionPool()
{
    pSessionPool = new SessionPool("SQLite",
        Application::instance().config().getString("application.configDir").append("/dummy.db"));
}


void destorySessionPool()
{
    delete pSessionPool;
}