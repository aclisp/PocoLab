#include "PrecompiledHeaders.h"
#include "CommonUtils.h"
#include "LightWeightServer.h"


using Poco::Util::AbstractConfiguration;
using Poco::Util::Application;
using Poco::Net::HTTPServer;
using Poco::Timespan;
using Poco::DateTimeFormatter;
using std::string;


bool hasSuffix(const string &str, const string &suffix)
{
	return str.size() >= suffix.size() &&
		str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
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

