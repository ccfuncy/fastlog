#ifndef FORMATTER_HPP
#define FORMATTER_HPP

#include <string>

using std::string;
namespace ccfuncy {
class LogMessage;
class Formatter {
   public:
    virtual string format(ccfuncy::LogMessage*) = 0;
};
}  // namespace ccfuncy
#endif
