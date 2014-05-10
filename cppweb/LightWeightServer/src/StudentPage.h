#ifndef StudentPage_INCLUDED
#define StudentPage_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


class StudentPage: public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


#endif // StudentPage_INCLUDED
