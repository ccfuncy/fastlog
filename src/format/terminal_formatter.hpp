#ifndef TERMINAL_FORMATTER
#define TERMINAL_FORMATTER
#include <iostream>

#include "../log.hpp"
namespace ccfuncy {

class TerminalFormatter : virtual public Formatter {
   public:
    TerminalFormatter() : Formatter(std::cout){};
    string format(LogMessage* msg) override {
        stringstream ss;
        ss << ColorPlate[msg->level]
           << ccfuncy::LogType::_from_index(msg->level)._to_string()[0]
           << msg->formatTime() << "   " << msg->getID() << msg->file << ":"
           << msg->line << "] " << msg->message << std::endl;
        return ss.str();
    };
};
}  // namespace ccfuncy

#endif
