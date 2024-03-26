#ifndef TXT_FORMATTER
#define TXT_FORMATTER
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <ostream>
#include <sstream>
#include <utility>

using namespace std;
#include "../log.hpp"
namespace ccfuncy {
class TxtFormatter : virtual public Formatter {
   public:
    ofstream of;
    TxtFormatter(std::ofstream os) : of(std::move(os)), Formatter(of) {}
    string format(LogMessage* msg) override {
        stringstream ss;
        ss << ccfuncy::LogType::_from_index(msg->level)._to_string()[0]
           << msg->formatTime() << "   " << msg->getID() << msg->file << ":"
           << msg->line << "] " << msg->message << std::endl;
        return ss.str();
    }
    ~TxtFormatter() {}

   private:
    TxtFormatter();
};
}  // namespace ccfuncy
#endif
