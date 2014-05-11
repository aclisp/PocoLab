#ifndef CommonUtils_INCLUDED
#define CommonUtils_INCLUDED


typedef std::map<std::string, std::string> StringMap;


bool hasSuffix(const std::string &str, const std::string &suffix);
void getApplicationProperties(const std::string& base, StringMap& prop);
void getRuntimeProperties(StringMap& prop);


#endif // CommonUtils_INCLUDED
