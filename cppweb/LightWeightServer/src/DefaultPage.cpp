#include "PrecompiledHeaders.h"
#include "DefaultPage.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"


#include "CommonUtils.h"
#line 7 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"

    using Poco::DateTimeFormatter;
    using Poco::DateTime;
    using Poco::Logger;
    using std::string;
    using std::map;
    using std::vector;
    using namespace Poco::Data;

    static Logger& logger()
    {
        return Logger::get("page.default");
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
#line 22 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"

    DateTime current;
    string dt = DateTimeFormatter::format(current, "%W, %e %b %y %H:%M:%S %Z");
    //poco_debug(logger(), request.getURI());

    StringMap runtimeProp;
    getRuntimeProperties(runtimeProp);

    StringMap appProp;
    getApplicationProperties("", appProp);

    vector<int> threadPoolAvailable;
    vector<int> serverCurrentThreads;
    vector<int> serverCurrentConnections;
    vector<int> serverQueuedConnections;
    vector<int> databaseSessionAllocated;
    vector<int> databaseSessionUsed;

    Session db(getSession());
    db << "SELECT ThreadPoolAvailable,ServerCurrentThreads,ServerCurrentConnections,ServerQueuedConnections,"
        "DatabaseSessionAllocated,DatabaseSessionUsed "
        "FROM PerformanceCounters",
        into(threadPoolAvailable),
        into(serverCurrentThreads),
        into(serverCurrentConnections),
        into(serverQueuedConnections),
        into(databaseSessionAllocated),
        into(databaseSessionUsed),
        now;
    db.close();
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
	responseStream << "        <script language=\"javascript\" type=\"text/javascript\" src=\"/js/excanvas.min.js\"></script>\n";
	responseStream << "        <![endif]-->\n";
	responseStream << "    </head>\n";
	responseStream << "    <body>\n";
	responseStream << "        <p style=\"text-align: center; font-size: 48px;\">";
#line 71 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( dt );
	responseStream << "</p>\n";
	responseStream << "        <div id=\"threadChart\" style=\"width:600px;height:300px\"></div>\n";
	responseStream << "        <div id=\"queueChart\" style=\"width:600px;height:100px\"></div>\n";
	responseStream << "        <h1>Server Runtime Properties</h1>\n";
	responseStream << "        <div class=\"table-responsive\"> <table class=\"table table-striped table-condensed table-hover\">\n";
	responseStream << "            <thead> <tr>\n";
	responseStream << "                <th>Name</th>\n";
	responseStream << "                <th>Value</th>\n";
	responseStream << "            </tr> </thead>\n";
	responseStream << "            <tbody>\n";
	responseStream << "            ";
#line 81 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 for (StringMap::const_iterator it = runtimeProp.begin(); it != runtimeProp.end(); ++it) { 	responseStream << "\n";
	responseStream << "            <tr>\n";
	responseStream << "                <td>";
#line 83 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( it->first );
	responseStream << "</td>\n";
	responseStream << "                <td>";
#line 84 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( it->second );
	responseStream << "</td>\n";
	responseStream << "            </tr>\n";
	responseStream << "            ";
#line 86 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
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
#line 96 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 for (StringMap::const_iterator it = appProp.begin(); it != appProp.end(); ++it) { 	responseStream << "\n";
	responseStream << "            <tr>\n";
	responseStream << "                <td>";
#line 98 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( it->first );
	responseStream << "</td>\n";
	responseStream << "                <td>";
#line 99 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( it->second );
	responseStream << "</td>\n";
	responseStream << "            </tr>\n";
	responseStream << "            ";
#line 101 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 } 	responseStream << "\n";
	responseStream << "            </tbody>\n";
	responseStream << "        </table> </div>\n";
	responseStream << "        <script src=\"/js/jquery.min.js\"></script>\n";
	responseStream << "        <script src=\"/js/jquery.flot.min.js\"></script>\n";
	responseStream << "        <script src=\"/js/bootstrap.min.js\"></script>\n";
	responseStream << "        <script>\n";
	responseStream << "            $.plot($(\"#threadChart\"), [\n";
	responseStream << "\n";
	responseStream << "                { label: \"ThreadPoolAvailable\", data: [\n";
	responseStream << "                    ";
#line 111 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 for (vector<int>::const_iterator it = threadPoolAvailable.begin(); it != threadPoolAvailable.end(); ++it) { 	responseStream << "\n";
	responseStream << "                        [";
#line 112 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( it - threadPoolAvailable.begin() );
	responseStream << " , ";
#line 112 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( *it );
	responseStream << "],\n";
	responseStream << "                    ";
#line 113 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 } 	responseStream << "\n";
	responseStream << "                ]},\n";
	responseStream << "\n";
	responseStream << "                { label: \"ServerCurrentThreads\", data: [\n";
	responseStream << "                    ";
#line 117 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 for (vector<int>::const_iterator it = serverCurrentThreads.begin(); it != serverCurrentThreads.end(); ++it) { 	responseStream << "\n";
	responseStream << "                        [";
#line 118 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( it - serverCurrentThreads.begin() );
	responseStream << " , ";
#line 118 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( *it );
	responseStream << "],\n";
	responseStream << "                    ";
#line 119 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 } 	responseStream << "\n";
	responseStream << "                ]},\n";
	responseStream << "\n";
	responseStream << "                { label: \"ServerCurrentConnections\", data: [\n";
	responseStream << "                    ";
#line 123 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 for (vector<int>::const_iterator it = serverCurrentConnections.begin(); it != serverCurrentConnections.end(); ++it) { 	responseStream << "\n";
	responseStream << "                        [";
#line 124 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( it - serverCurrentConnections.begin() );
	responseStream << " , ";
#line 124 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( *it );
	responseStream << "],\n";
	responseStream << "                    ";
#line 125 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 } 	responseStream << "\n";
	responseStream << "                ]},\n";
	responseStream << "\n";
	responseStream << "                { label: \"DatabaseSessionAllocated\", data: [\n";
	responseStream << "                    ";
#line 129 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 for (vector<int>::const_iterator it = databaseSessionAllocated.begin(); it != databaseSessionAllocated.end(); ++it) { 	responseStream << "\n";
	responseStream << "                        [";
#line 130 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( it - databaseSessionAllocated.begin() );
	responseStream << " , ";
#line 130 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( *it );
	responseStream << "],\n";
	responseStream << "                    ";
#line 131 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 } 	responseStream << "\n";
	responseStream << "                ]},\n";
	responseStream << "\n";
	responseStream << "                { label: \"DatabaseSessionUsed\", data: [\n";
	responseStream << "                    ";
#line 135 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 for (vector<int>::const_iterator it = databaseSessionUsed.begin(); it != databaseSessionUsed.end(); ++it) { 	responseStream << "\n";
	responseStream << "                        [";
#line 136 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( it - databaseSessionUsed.begin() );
	responseStream << " , ";
#line 136 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( *it );
	responseStream << "],\n";
	responseStream << "                    ";
#line 137 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 } 	responseStream << "\n";
	responseStream << "                ]},\n";
	responseStream << "\n";
	responseStream << "            ], { xaxis: { max: 180 }, yaxis: { max: ";
#line 140 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( getThreadPool().capacity() );
	responseStream << " } });\n";
	responseStream << "\n";
	responseStream << "            $.plot($(\"#queueChart\"), [\n";
	responseStream << "\n";
	responseStream << "                { label: \"ServerQueuedConnections\", data: [\n";
	responseStream << "                    ";
#line 145 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 for (vector<int>::const_iterator it = serverQueuedConnections.begin(); it != serverQueuedConnections.end(); ++it) { 	responseStream << "\n";
	responseStream << "                        [";
#line 146 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( it - serverQueuedConnections.begin() );
	responseStream << " , ";
#line 146 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( *it );
	responseStream << "],\n";
	responseStream << "                    ";
#line 147 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 } 	responseStream << "\n";
	responseStream << "                ]},\n";
	responseStream << "\n";
	responseStream << "            ], { xaxis: { max: 180 }, yaxis: { max: ";
#line 150 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( appProp["tcpserver.maxQueued"] );
	responseStream << " } });\n";
	responseStream << "        </script>\n";
	responseStream << "    </body>\n";
	responseStream << "</html>\n";
	responseStream << "";
}
