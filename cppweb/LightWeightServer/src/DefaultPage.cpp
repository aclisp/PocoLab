#include "PrecompiledHeaders.h"
#include "DefaultPage.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"


#include "LightWeightServer.h"
#line 7 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"

    using Poco::Util::AbstractConfiguration;
    using Poco::Util::Application;
    using Poco::Net::HTTPServer;
    using Poco::DateTimeFormatter;
    using Poco::DateTime;
    using Poco::Logger;
    using Poco::Timespan;
    using std::string;
    using std::map;

    typedef map<string, string> StringMap;

    Logger& logger()
    {
        return Logger::get("page.default");
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


void DefaultPage::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("text/html");

	Poco::Net::HTMLForm form(request, request.stream());
	std::ostream& responseStream = response.send();
	responseStream << "";
	responseStream << "\n";
	responseStream << "\n";
	responseStream << "";
	responseStream << "\n";
	responseStream << "\n";
	responseStream << "";
	responseStream << "\n";
	responseStream << "\n";
	responseStream << "";
#line 63 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"

    DateTime now;
    string dt = DateTimeFormatter::format(now, "%W, %e %b %y %H:%M:%S %Z");
    //poco_debug(logger(), request.getURI());

    StringMap runtimeProp;
    getRuntimeProperties(runtimeProp);

    StringMap appProp;
    getApplicationProperties("", appProp);
	responseStream << "\n";
	responseStream << "\n";
	responseStream << "<!DOCTYPE html>\n";
	responseStream << "<html lang=\"en\">\n";
	responseStream << "    <head>\n";
	responseStream << "        <meta charset=\"utf-8\">\n";
	responseStream << "        <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n";
	responseStream << "        <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n";
	responseStream << "        <title>LightWeightServer powered by POCO C++ Libraries and PageCompiler</title>\n";
	responseStream << "        <link href=\"/css/bootstrap.min.css\" rel=\"stylesheet\">\n";
	responseStream << "        <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n";
	responseStream << "        <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n";
	responseStream << "        <!--[if lt IE 9]>\n";
	responseStream << "        <script src=\"https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js\"></script>\n";
	responseStream << "        <script src=\"https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js\"></script>\n";
	responseStream << "        <![endif]-->\n";
	responseStream << "    </head>\n";
	responseStream << "    <body>\n";
	responseStream << "        <p style=\"text-align: center; font-size: 48px;\">";
#line 91 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( dt );
	responseStream << "</p>\n";
	responseStream << "        <h1>Server Runtime Properties</h1>\n";
	responseStream << "        <div class=\"table-responsive\"> <table class=\"table table-striped table-condensed table-hover\">\n";
	responseStream << "            <thead> <tr>\n";
	responseStream << "                <th>Name</th>\n";
	responseStream << "                <th>Value</th>\n";
	responseStream << "            </tr> </thead>\n";
	responseStream << "            <tbody>\n";
	responseStream << "            ";
#line 99 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 for (StringMap::const_iterator it = runtimeProp.begin(); it != runtimeProp.end(); ++it) { 	responseStream << "\n";
	responseStream << "            <tr>\n";
	responseStream << "                <td>";
#line 101 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( it->first );
	responseStream << "</td>\n";
	responseStream << "                <td>";
#line 102 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( it->second );
	responseStream << "</td>\n";
	responseStream << "            </tr>\n";
	responseStream << "            ";
#line 104 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 } 	responseStream << "\n";
	responseStream << "            </tbody>\n";
	responseStream << "        </table> </div>\n";
	responseStream << "        <h1>Application Properties</h1>\n";
	responseStream << "        <div class=\"table-responsive\"> <table class=\"table table-striped table-condensed table-hover\">\n";
	responseStream << "            <thead> <tr>\n";
	responseStream << "                <th>Name</th>\n";
	responseStream << "                <th>Value</th>\n";
	responseStream << "            </tr> </thead>\n";
	responseStream << "            <tbody>\n";
	responseStream << "            ";
#line 114 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 for (StringMap::const_iterator it = appProp.begin(); it != appProp.end(); ++it) { 	responseStream << "\n";
	responseStream << "            <tr>\n";
	responseStream << "                <td>";
#line 116 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( it->first );
	responseStream << "</td>\n";
	responseStream << "                <td>";
#line 117 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( it->second );
	responseStream << "</td>\n";
	responseStream << "            </tr>\n";
	responseStream << "            ";
#line 119 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 } 	responseStream << "\n";
	responseStream << "            </tbody>\n";
	responseStream << "        </table> </div>\n";
	responseStream << "        <script src=\"/js/jquery.min.js\"></script>\n";
	responseStream << "        <script src=\"/js/bootstrap.min.js\"></script>\n";
	responseStream << "    </body>\n";
	responseStream << "</html>\n";
	responseStream << "";
}
