#include "PrecompiledHeaders.h"
#include "StudentPage.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"


#include "LightWeightServer.h"
#line 11 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentPage.cpsp"

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

    static Logger& logger()
    {
        return Logger::get("page.default");
    }


void StudentPage::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("text/html");

	Poco::Net::HTMLForm form(request, request.stream());
	std::ostream& responseStream = response.send();
	responseStream << "";
	responseStream << " ";
	responseStream << "\n";
	responseStream << "\n";
	responseStream << "";
	responseStream << " ";
	responseStream << "\n";
	responseStream << "\n";
	responseStream << "";
	responseStream << "\n";
	responseStream << "";
	responseStream << "\n";
	responseStream << "\n";
	responseStream << "";
	responseStream << "\n";
	responseStream << "";
#line 31 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentPage.cpsp"

	responseStream << "\n";
	responseStream << "\n";
	responseStream << "<!DOCTYPE html>\n";
	responseStream << "<html lang=\"en\">\n";
	responseStream << "    <head>\n";
	responseStream << "        <meta charset=\"utf-8\">\n";
	responseStream << "        <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n";
	responseStream << "        <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n";
	responseStream << "        <title>Template Page powered by POCO C++ Libraries and PageCompiler</title>\n";
	responseStream << "        <link href=\"/css/bootstrap.min.css\" rel=\"stylesheet\">\n";
	responseStream << "        <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n";
	responseStream << "        <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n";
	responseStream << "        <!--[if lt IE 9]>\n";
	responseStream << "        <script src=\"https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js\"></script>\n";
	responseStream << "        <script src=\"https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js\"></script>\n";
	responseStream << "        <![endif]-->\n";
	responseStream << "    </head>\n";
	responseStream << "    <body>\n";
	responseStream << "        <h1>Hello, world!</h1>\n";
	responseStream << "\n";
	responseStream << "        <!-- TODO start your page from here -->\n";
	responseStream << "\n";
	responseStream << "        <script src=\"/js/jquery.min.js\"></script>\n";
	responseStream << "        <script src=\"/js/bootstrap.min.js\"></script>\n";
	responseStream << "    </body>\n";
	responseStream << "</html>\n";
	responseStream << "";
}
