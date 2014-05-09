#ifndef RestfulDatabaseHandler_INCLUDED
#define RestfulDatabaseHandler_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


class RestfulDatabaseHandler: public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


#endif // RestfulDatabaseHandler_INCLUDED
