#include "PrecompiledHeaders.h"
#include "DefaultRequestHandlerFactory.h"
#include "DefaultPage.h"


using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Util::Application;
using Poco::Logger;
using Poco::AbstractInstantiator;
using Poco::Instantiator;
using Poco::SharedPtr;
using Poco::URI;
using Poco::RegularExpression;
using std::string;
using std::vector;


namespace {


static
bool hasSuffix(const std::string &str, const std::string &suffix)
{
    return str.size() >= suffix.size() &&
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}


class StaticFileHandler: public Poco::Net::HTTPRequestHandler
{
public:
    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
    {
        //poco_debug(logger(), request.getURI());

        URI uri(request.getURI());
		const string& path = uri.getPath();

        response.sendFile(
			Application::instance().config().getString("application.configDir").append(path),
			getMediaType(path));
    }
private:
    string getMediaType(const string& uriPath)
    {
        if (hasSuffix(uriPath, ".js"))            return "application/javascript";
        else if (hasSuffix(uriPath, ".css"))      return "text/css";
		else if (hasSuffix(uriPath, ".svg"))      return "image/svg+xml";
		else if (hasSuffix(uriPath, ".ttf"))      return "application/x-font-truetype";
		else if (hasSuffix(uriPath, ".otf"))      return "application/x-font-opentype";
		else if (hasSuffix(uriPath, ".woff"))     return "application/font-woff";
		else if (hasSuffix(uriPath, ".eot"))      return "application/vnd.ms-fontobject";
        else                                      return "";
    }
    Poco::Logger& logger()
    {
        return Poco::Logger::get("page.static");
    }
};


class Navigation
{
public:
    typedef AbstractInstantiator<HTTPRequestHandler> Factory;
    typedef SharedPtr<Factory> FactoryPtr;
    typedef SharedPtr<RegularExpression> RegExpPtr;
    Navigation(const string& httpMethod, const string& uriPathPattern, FactoryPtr pFactory)
        : _httpMethod(httpMethod), _pFactory(pFactory)
    {
        string pat;
        pat.append("^") // match from the beginning of uri.path
           .append(uriPathPattern)
           .append("$"); // match to the end of uri.path
        _pUriPathRegExp = new RegularExpression(pat);
    }
    bool match(const string& httpMethod, const string& uriPath) const
    {
        return _httpMethod == httpMethod && _pUriPathRegExp->match(uriPath);
    }
    HTTPRequestHandler* createHandler() const
    {
        return _pFactory->createInstance();
    }
private:
    string _httpMethod;
    RegExpPtr _pUriPathRegExp;
    FactoryPtr _pFactory;
};


static vector<Navigation> navigationRules;
typedef vector<Navigation> NavVector;


template <class Handler>
static
void addNav(const string& httpMethod, const string& uriPathPattern)
{
    navigationRules.push_back(
        Navigation(
            httpMethod,
            uriPathPattern,
            new Instantiator<Handler, HTTPRequestHandler>));
}


} // end of unnamed namespace


DefaultRequestHandlerFactory::DefaultRequestHandlerFactory()
{

    addNav <DefaultPage>             ("GET", "/");

    addNav <StaticFileHandler>       ("GET", "/js/[\\w\\.-]+\\.js"); // "application/javascript"
    addNav <StaticFileHandler>       ("GET", "/css/[\\w\\.-]+\\.css"); // "text/css"
	addNav <StaticFileHandler>       ("GET", "/fonts/[\\w\\.-]+\\.[\\w]+");

//    addNav <StudentListPage>         ("GET", "/student") // return a list of all records
//    addNav <StudentPage>             ("GET", "/student/new") // return a form for creating a new record
//    addNav <StudentPage>             ("GET", "/student/\d+/edit") // return a form to edit the record by id
//    addNav <StudentPage>             ("GET", "/student/\d+") // return the record by id

//    addNav <StudentCRUDHandler>      ("POST", "/student") // submit fields for creating a new record
//    addNav <StudentCRUDHandler>      ("POST", "/student/\d+") // destroy or submit fields for updating the record by id

	poco_debug_f1(Application::instance().logger(), "add %z navigation rules", navigationRules.size());
}


DefaultRequestHandlerFactory::~DefaultRequestHandlerFactory()
{
}


HTTPRequestHandler* DefaultRequestHandlerFactory::createRequestHandler(const HTTPServerRequest& request)
{
    //poco_debug_f2(Logger::get("page.entry"), "%s %s", request.getMethod(), request.getURI());
    URI uri(request.getURI());

    for (NavVector::const_iterator it = navigationRules.begin(); it != navigationRules.end(); ++it)
    {
        if ( it->match(request.getMethod(), uri.getPath()) )
        {
			poco_debug_f2(Logger::get("page.entry"), "Match %s %s", request.getMethod(), request.getURI());
            return it->createHandler();
        }
    }

	poco_debug_f2(Logger::get("page.entry"), "Not found %s %s", request.getMethod(), request.getURI());
    return 0;

//    if (request.getURI() == "/")
//        return new DefaultPageHandler;
//    else if (request.getURI().find("/js/") == 0)
//        return new StaticFileHandler("application/javascript");
//    else if (request.getURI().find("/css/") == 0)
//        return new StaticFileHandler("text/css");
//    else
//        return 0;
}



