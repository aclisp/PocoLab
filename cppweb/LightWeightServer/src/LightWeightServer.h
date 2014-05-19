#ifndef LightWeightServer_INCLUDED
#define LightWeightServer_INCLUDED


#include "Poco/Util/ServerApplication.h"


namespace Poco {
namespace Net {

class HTTPServer;

}
}


class LightWeightServer : public Poco::Util::ServerApplication
    /// The main application class.
    ///
    /// This class handles command-line arguments and
    /// configuration files.
    /// Start the HTTPTimeServer executable with the help
    /// option (/help on Windows, --help on Unix) for
    /// the available command line options.
    ///
    /// To use the sample configuration file (HTTPTimeServer.properties),
    /// copy the file to the directory where the HTTPTimeServer executable
    /// resides. If you start the debug version of the HTTPTimeServer
    /// (HTTPTimeServerd[.exe]), you must also create a copy of the configuration
    /// file named HTTPTimeServerd.properties. In the configuration file, you
    /// can specify the port on which the server is listening (default
    /// 9980) and the format of the date/time string sent back to the client.
    ///
    /// To test the TimeServer you can use any web browser (http://localhost:9980/).
{
    public:
        LightWeightServer() : _helpRequested(false) { }
        ~LightWeightServer() { }
        const Poco::Net::HTTPServer& server() const { return *_pServer; }

    protected:
        void initialize(Poco::Util::Application& self);
        void uninitialize();
        void defineOptions(Poco::Util::OptionSet& options);
        void handleOption(const std::string& name, const std::string& value);
        void displayHelp();
        int main(const std::vector<std::string>& args);

    private:
        void onRecordPerformanceCounters(Poco::Timer& timer);
        bool _helpRequested;
        const Poco::Net::HTTPServer* _pServer;
};

#endif // LightWeightServer_INCLUDED
