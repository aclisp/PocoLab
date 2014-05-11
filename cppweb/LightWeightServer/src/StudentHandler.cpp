#include "PrecompiledHeaders.h"
#include "StudentHandler.h"


using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTMLForm;


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
}