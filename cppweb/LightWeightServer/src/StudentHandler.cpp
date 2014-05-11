#include "PrecompiledHeaders.h"
#include "StudentHandler.h"
#include "CommonUtils.h"


using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTMLForm;
using std::string;
using namespace Poco::Data;


static Poco::Logger& logger()
{
    return Poco::Logger::get("page.student");
}


void StudentHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
    poco_assert_dbg(request.getMethod() == "POST");
    HTMLForm form(request, request.stream());

    poco_debug_f4(logger(), "%s id=%s name=%s tel=%s", 
        form["_method"], form["id"], 
        form.get("name", ""), form.get("tel", ""));

    Session db(getSession());

    if (form["_method"] == "POST") {
        db << "INSERT INTO STUDENT VALUES (NULL,?,?)", use(form["name"]), use(form["tel"]), now;
        string studentId;
        db << "SELECT last_insert_rowid()", into(studentId), now;
        response.redirect("/student/" + studentId);
    }
    else if (form["_method"] == "PUT") {
        db << "UPDATE STUDENT SET NAME=?,TEL=? WHERE ID=?", use(form["name"]), use(form["tel"]), use(form["id"]), now;
        response.redirect("/student/" + form["id"]);
    }
    else if (form["_method"] == "DELETE") {
        db << "DELETE FROM STUDENT WHERE ID=?", use(form["id"]), now;
        response.redirect("/student");
    }
    else {
    	poco_bugcheck();
    }
}