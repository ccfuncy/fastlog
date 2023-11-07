#ifndef TXT_FORMATTER
#define TXT_FORMATTER
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>

using namespace std;
#include "../log.hpp"
namespace ccfuncy {
class TxtFormatter : virtual public Formatter {
   public:
    TxtFormatter(ofstream& os) : Formatter(os) {}
    string format(LogMessage* msg) override {
        stringstream ss;
        ss << ccfuncy::LogType::_from_index(msg->level)._to_string()[0]
           << msg->formatTime() << "   " << msg->getID() << msg->file << ":"
           << msg->line << "] " << msg->message << std::endl;
        return ss.str();
    }

   private:
    TxtFormatter();
};
}  // namespace ccfuncy
#endif
