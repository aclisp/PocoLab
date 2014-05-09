#ifndef DefaultRequestHandlerFactory_INCLUDED
#define DefaultRequestHandlerFactory_INCLUDED


#include "Poco/Net/HTTPRequestHandlerFactory.h"


class DefaultRequestHandlerFactory: public Poco::Net::HTTPRequestHandlerFactory
{
    public:
        DefaultRequestHandlerFactory();
        ~DefaultRequestHandlerFactory();
        Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request);
};


#endif // DefaultRequestHandlerFactory_INCLUDED
