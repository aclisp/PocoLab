#include "PrecompiledHeaders.h"
#include "StudentListPage.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"


#include "CommonUtils.h"
#line 11 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentListPage.cpsp"

    using Poco::Tuple;
    using Poco::Logger;
    using std::string;
    using namespace Poco::Data;

    static Logger& logger()
    {
        return Logger::get("page.student");
    }


void StudentListPage::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
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
#line 24 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentListPage.cpsp"

    typedef Tuple<string, string, string> Student;
    typedef std::vector<Student> StudentVector;

    Session db(getSession());
    StudentVector studentVector;
    db << "SELECT ID,NAME,TEL FROM STUDENT", into(studentVector), now;
	responseStream << "\n";
	responseStream << "\n";
	responseStream << "<!DOCTYPE html>\n";
	responseStream << "<html lang=\"en\">\n";
	responseStream << "    <head>\n";
	responseStream << "        <meta charset=\"utf-8\">\n";
	responseStream << "        <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n";
	responseStream << "        <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n";
	responseStream << "        <title>All Students</title>\n";
	responseStream << "        <link href=\"/css/bootstrap.min.css\" rel=\"stylesheet\">\n";
	responseStream << "        <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n";
	responseStream << "        <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n";
	responseStream << "        <!--[if lt IE 9]>\n";
	responseStream << "        <script src=\"https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js\"></script>\n";
	responseStream << "        <script src=\"https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js\"></script>\n";
	responseStream << "        <![endif]-->\n";
	responseStream << "    </head>\n";
	responseStream << "    <body>\n";
	responseStream << "        <h1>All Students</h1>\n";
	responseStream << "\n";
	responseStream << "        <a href=\"/student/new\" class=\"btn btn-primary\">\n";
	responseStream << "            <span class=\"glyphicon glyphicon-plus\"></span> Add a New Student\n";
	responseStream << "        </a>\n";
	responseStream << "\n";
	responseStream << "        <div class=\"table-responsive\"> <table class=\"table table-striped table-condensed table-hover\">\n";
	responseStream << "            <thead> <tr>\n";
	responseStream << "                <th>Name</th>\n";
	responseStream << "                <th>Telephone number</th>\n";
	responseStream << "                <th>Action</th>\n";
	responseStream << "            </tr> </thead>\n";
	responseStream << "            <tbody>\n";
	responseStream << "            ";
#line 62 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentListPage.cpsp"
 for (StudentVector::const_iterator it = studentVector.begin(); it != studentVector.end(); ++it) { 	responseStream << "\n";
	responseStream << "            <tr>\n";
	responseStream << "                <td>";
#line 64 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentListPage.cpsp"
	responseStream << ( it->get<1>() );
	responseStream << "</td>\n";
	responseStream << "                <td>";
#line 65 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentListPage.cpsp"
	responseStream << ( it->get<2>() );
	responseStream << "</td>\n";
	responseStream << "                <td>\n";
	responseStream << "                    <a href=\"/student/";
#line 67 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentListPage.cpsp"
	responseStream << ( it->get<0>() );
	responseStream << "\">\n";
	responseStream << "                        <span class=\"glyphicon glyphicon-list\"></span>\n";
	responseStream << "                    </a>\n";
	responseStream << "                    &nbsp;&nbsp;&nbsp;&nbsp;\n";
	responseStream << "                    <a href=\"/student/";
#line 71 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentListPage.cpsp"
	responseStream << ( it->get<0>() );
	responseStream << "/edit\">\n";
	responseStream << "                        <span class=\"glyphicon glyphicon-edit\"></span>\n";
	responseStream << "                    </a>\n";
	responseStream << "                </td>\n";
	responseStream << "            </tr>\n";
	responseStream << "            ";
#line 76 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentListPage.cpsp"
 } 	responseStream << "\n";
	responseStream << "            </tbody>\n";
	responseStream << "        </table> </div>\n";
	responseStream << "\n";
	responseStream << "        <script src=\"/js/jquery.min.js\"></script>\n";
	responseStream << "        <script src=\"/js/bootstrap.min.js\"></script>\n";
	responseStream << "    </body>\n";
	responseStream << "</html>\n";
	responseStream << "";
}
