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


/*
    CREATE TABLE Student (
        Id INTEGER PRIMARY KEY AUTOINCREMENT,
        Name TEXT,
        TelephoneNumber TEXT
    );
 */


static void doPost(HTTPServerRequest& request, HTTPServerResponse& response, const HTMLForm& form)
{
    Session db(getSession());
    db << "INSERT INTO Student VALUES (NULL,?,?)", use(form["name"]), use(form["tel"]), now;
    string studentId;
    db << "SELECT last_insert_rowid()", into(studentId), now;
    response.redirect(Poco::format("/student/%s/edit", studentId));
}


static void doPut(HTTPServerRequest& request, HTTPServerResponse& response, const HTMLForm& form)
{
    Session db(getSession());
    db << "UPDATE Student SET Name=?,TelephoneNumber=? WHERE Id=?", use(form["name"]), use(form["tel"]), use(form["id"]), now;
    response.redirect(Poco::format("/student/%s/edit", form["id"]));
}


static void doDelete(HTTPServerRequest& request, HTTPServerResponse& response, const HTMLForm& form)
{
    Session db(getSession());
    db << "DELETE FROM Student WHERE Id=?", use(form["id"]), now;
    response.redirect("/student");
}


void StudentHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
    poco_assert_dbg(request.getMethod() == "POST");
    HTMLForm form(request, request.stream());

    poco_debug_f4(logger(), "%s id=%s name=%s tel=%s", 
        form["_method"], form["id"], 
        form.get("name", ""), form.get("tel", ""));

    if (form["_method"] == "POST") {
        doPost(request, response, form);
    }
    else if (form["_method"] == "PUT") {
        doPut(request, response, form);
    }
    else if (form["_method"] == "DELETE") {
        doDelete(request, response, form);
    }
    else {
    	poco_bugcheck();
    }
}