#ifndef StudentListPage_INCLUDED
#define StudentListPage_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


class StudentListPage: public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


#endif // StudentListPage_INCLUDED
