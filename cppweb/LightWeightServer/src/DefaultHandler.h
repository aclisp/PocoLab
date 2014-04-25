//
// TimeHandler.h
//
// This file has been generated from TimeHandler.cpsp on 2010-01-28 08:49:54.
//


#ifndef DefaultHandler_INCLUDED
#define DefaultHandler_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


class DefaultHandler : public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


#endif // DefaultHandler_INCLUDED
