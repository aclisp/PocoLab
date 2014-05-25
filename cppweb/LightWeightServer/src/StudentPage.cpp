#include "PrecompiledHeaders.h"
#include "StudentPage.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"


#include "CommonUtils.h"
#line 11 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentPage.cpsp"

    using Poco::Logger;
    using std::string;
    using namespace Poco::Data;

    static Logger& logger()
    {
        return Logger::get("page.student");
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
#line 23 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentPage.cpsp"

    string title = "Student Information";
    string action = "#";

    string studentId = getId(request);
    //poco_debug_f1(logger(), "id=%s", studentId);
    string studentName;
    string studentTel;

    if (IsNew(request)) {
        title = "Add a New Student";
        action = "/student";
    }
    else { // find student by Id
        Session db(getSession());
        db << "SELECT Name,TelephoneNumber FROM Student WHERE Id=?", 
              into(studentName),
              into(studentTel),
              use(studentId),
              lowerLimit(1),
              now;

        if (IsEdit(request)) {
            title = "Student Information";
            action = "/student/" + studentId;
        }
    }
	responseStream << "\n";
	responseStream << "\n";
	responseStream << "<!DOCTYPE html>\n";
	responseStream << "<html lang=\"en\">\n";
	responseStream << "    <head>\n";
	responseStream << "        <meta charset=\"utf-8\">\n";
	responseStream << "        <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n";
	responseStream << "        <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n";
	responseStream << "        <title>";
#line 58 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentPage.cpsp"
	responseStream << ( title );
	responseStream << "</title>\n";
	responseStream << "        <link href=\"/css/bootstrap.min.css\" rel=\"stylesheet\">\n";
	responseStream << "        <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n";
	responseStream << "        <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n";
	responseStream << "        <!--[if lt IE 9]>\n";
	responseStream << "        <script src=\"https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js\"></script>\n";
	responseStream << "        <script src=\"https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js\"></script>\n";
	responseStream << "        <![endif]-->\n";
	responseStream << "    </head>\n";
	responseStream << "    <body>\n";
	responseStream << "        <ol class=\"breadcrumb\">\n";
	responseStream << "            <li><a href=\"/student\">All Student</a></li>\n";
	responseStream << "            <li class=\"active\">";
#line 70 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentPage.cpsp"
	responseStream << ( title );
	responseStream << "</li>\n";
	responseStream << "        </ol>\n";
	responseStream << "\n";
	responseStream << "        <h1>";
#line 73 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentPage.cpsp"
	responseStream << ( title );
	responseStream << "</h1>\n";
	responseStream << "\n";
	responseStream << "        <form action=\"";
#line 75 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentPage.cpsp"
	responseStream << ( action );
	responseStream << "\" method=\"post\">\n";
	responseStream << "\n";
	responseStream << "            ";
#line 77 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentPage.cpsp"
 if (IsEdit(request)) { 	responseStream << "\n";
	responseStream << "            <div class=\"pull-right\">\n";
	responseStream << "                <button type=\"button\" class=\"btn btn-link\" \n";
	responseStream << "                        onclick=\"this.form._method.value='DELETE'; this.form.submit()\">\n";
	responseStream << "                    <span class=\"glyphicon glyphicon-remove-sign\"></span> Delete\n";
	responseStream << "                </button>\n";
	responseStream << "                <a href=\"/student/new\" class=\"btn btn-link\">\n";
	responseStream << "                    <span class=\"glyphicon glyphicon-plus-sign\"></span> New\n";
	responseStream << "                </a>\n";
	responseStream << "            </div>\n";
	responseStream << "            ";
#line 87 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentPage.cpsp"
 } 	responseStream << "\n";
	responseStream << "\n";
	responseStream << "            <input type=\"hidden\" name=\"id\" value=\"";
#line 89 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentPage.cpsp"
	responseStream << ( studentId );
	responseStream << "\" >\n";
	responseStream << "            <div class=\"form-group\">\n";
	responseStream << "                <label for=\"studentInputName1\">Name</label>\n";
	responseStream << "                <input type=\"text\" class=\"form-control\" id=\"studentInputName1\" placeholder=\"Name\" name=\"name\" value=\"";
#line 92 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentPage.cpsp"
	responseStream << ( studentName );
	responseStream << "\" >\n";
	responseStream << "            </div>\n";
	responseStream << "            <div class=\"form-group\">\n";
	responseStream << "                <label for=\"studentInputTel1\">Telephone number</label>\n";
	responseStream << "                <input type=\"text\" class=\"form-control\" id=\"studentInputTel1\" placeholder=\"Telephone number\" name=\"tel\" value=\"";
#line 96 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentPage.cpsp"
	responseStream << ( studentTel );
	responseStream << "\" >\n";
	responseStream << "            </div>\n";
	responseStream << "\n";
	responseStream << "            ";
#line 99 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentPage.cpsp"
 if (IsNew(request)) { 	responseStream << "\n";
	responseStream << "                <input type=\"hidden\" name=\"_method\" value=\"POST\" >\n";
	responseStream << "                <button type=\"submit\" class=\"btn btn-warning\">\n";
	responseStream << "                    <span class=\"glyphicon glyphicon-ok-sign\"></span> Save\n";
	responseStream << "                </button>\n";
	responseStream << "                <a href=\"/student\" class=\"btn btn-default\">Cancel</a>\n";
	responseStream << "            ";
#line 105 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentPage.cpsp"
 } 	responseStream << "\n";
	responseStream << "\n";
	responseStream << "            ";
#line 107 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentPage.cpsp"
 if (IsEdit(request)) { 	responseStream << "\n";
	responseStream << "                <input type=\"hidden\" name=\"_method\" value=\"PUT\" >\n";
	responseStream << "                <button type=\"submit\" class=\"btn btn-warning\">\n";
	responseStream << "                    <span class=\"glyphicon glyphicon-ok-sign\"></span> Save\n";
	responseStream << "                </button>\n";
	responseStream << "                <a href=\"/student\" class=\"btn btn-default\">Cancel</a>\n";
	responseStream << "            ";
#line 113 "D:\\CppDev\\PocoLab\\cppweb\\LightWeightServer\\src\\StudentPage.cpsp"
 } 	responseStream << "\n";
	responseStream << "\n";
	responseStream << "        </form>\n";
	responseStream << "\n";
	responseStream << "        <script src=\"/js/jquery.min.js\"></script>\n";
	responseStream << "        <script src=\"/js/bootstrap.min.js\"></script>\n";
	responseStream << "    </body>\n";
	responseStream << "</html>\n";
	responseStream << "";
}
