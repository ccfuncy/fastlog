#ifndef FORMATTER_HPP
#define FORMATTER_HPP

#include <fstream>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <utility>
using std::ostream;
using std::string;
namespace ccfuncy {
class LogMessage;
class Formatter {
   public:
    Formatter(ostream& outter) : outter(outter){};
    ostream& outter;
    virtual string format(ccfuncy::LogMessage*) = 0;
    void outIO(ccfuncy::LogMessage* msg) {
        outter << this->format(msg);
        outter.flush();
    };
};
}  // namespace ccfuncy
#endif
