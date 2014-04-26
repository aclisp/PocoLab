#include "DefaultHandler.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"


#include "Poco/DateTime.h"
#include "Poco/DateTimeFormatter.h"
#line 5 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultHandler.xml"

using Poco::DateTimeFormatter;
using Poco::DateTime;
using namespace std;


void DefaultHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("text/html");

	Poco::Net::HTMLForm form(request, request.stream());
	std::ostream& responseStream = response.send();
	responseStream << "";
	responseStream << "\n";
	responseStream << "";
	responseStream << "\n";
	responseStream << "";
	responseStream << "\n";
	responseStream << "";
#line 10 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultHandler.xml"

DateTime now;
string dt(DateTimeFormatter::format(now, "%W, %e %b %y %H:%M:%S %Z"));
	responseStream << "\n";
	responseStream << "<html>\n";
	responseStream << "  <head>\n";
	responseStream << "    <title>LightWeightServer powered by POCO C++ Libraries and PageCompiler</title>\n";
	responseStream << "    <meta http-equiv=\"refresh\" content=\"1\"/>\n";
	responseStream << "  </head>\n";
	responseStream << "  <body>\n";
	responseStream << "    <p style=\"text-align: center; font-size: 48px;\">\n";
	responseStream << "      ";
#line 21 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\DefaultHandler.xml"
	responseStream << ( dt );
	responseStream << "\n";
	responseStream << "    </p>\n";
	responseStream << "  </body>\n";
	responseStream << "</html>\n";
	responseStream << "";
}
