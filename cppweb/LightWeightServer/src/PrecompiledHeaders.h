#ifndef PrecompiledHeaders_INCLUDED
#define PrecompiledHeaders_INCLUDED

#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Application.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Util/AbstractConfiguration.h"
#include "Poco/LeakDetector.h"
#include "Poco/Thread.h"
#include "Poco/Logger.h"
#include "Poco/Instantiator.h"
#include "Poco/SharedPtr.h"
#include "Poco/URI.h"
#include "Poco/RegularExpression.h"
#include "Poco/DateTime.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/Timespan.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>

#endif // PrecompiledHeaders_INCLUDED
