#ifndef CommonUtils_INCLUDED
#define CommonUtils_INCLUDED


typedef std::map<std::string, std::string> StringMap;


bool hasSuffix(const std::string &str, const std::string &suffix);
bool IsEdit(const Poco::Net::HTTPServerRequest& request);
bool IsNew(const Poco::Net::HTTPServerRequest& request);
bool IsShow(const Poco::Net::HTTPServerRequest& request);
std::string getId(const Poco::Net::HTTPServerRequest& request);
void getApplicationProperties(const std::string& base, StringMap& prop);
void getRuntimeProperties(StringMap& prop);


#endif // CommonUtils_INCLUDED
