#ifndef StudentHandler_INCLUDED
#define StudentHandler_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


class StudentHandler: public Poco::Net::HTTPRequestHandler
{
public:
    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


#endif // StudentHandler_INCLUDED
