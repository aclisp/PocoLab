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
#line 20 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"

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
#line 48 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
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
#line 56 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 for (StringMap::const_iterator it = runtimeProp.begin(); it != runtimeProp.end(); ++it) { 	responseStream << "\n";
	responseStream << "            <tr>\n";
	responseStream << "                <td>";
#line 58 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( it->first );
	responseStream << "</td>\n";
	responseStream << "                <td>";
#line 59 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( it->second );
	responseStream << "</td>\n";
	responseStream << "            </tr>\n";
	responseStream << "            ";
#line 61 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
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
#line 71 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 for (StringMap::const_iterator it = appProp.begin(); it != appProp.end(); ++it) { 	responseStream << "\n";
	responseStream << "            <tr>\n";
	responseStream << "                <td>";
#line 73 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( it->first );
	responseStream << "</td>\n";
	responseStream << "                <td>";
#line 74 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
	responseStream << ( it->second );
	responseStream << "</td>\n";
	responseStream << "            </tr>\n";
	responseStream << "            ";
#line 76 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultPage.cpsp"
 } 	responseStream << "\n";
	responseStream << "            </tbody>\n";
	responseStream << "        </table> </div>\n";
	responseStream << "        <script src=\"/js/jquery.min.js\"></script>\n";
	responseStream << "        <script src=\"/js/bootstrap.min.js\"></script>\n";
	responseStream << "    </body>\n";
	responseStream << "</html>\n";
	responseStream << "";
}
