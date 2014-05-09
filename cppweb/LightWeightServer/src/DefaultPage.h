#ifndef DefaultPage_INCLUDED
#define DefaultPage_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


class DefaultPage: public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


#endif // DefaultPage_INCLUDED
