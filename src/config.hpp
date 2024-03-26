#ifndef CONFIG_HPP
#define CONFIG_HPP
#include <string>
#include <vector>

using namespace std;

#include "enum.h"
#include "format/formatter.hpp"
namespace ccfuncy {
BETTER_ENUM(LogType, int, DEBUG, INFO, WARN, ERROR, FATAL);
#define LOG(logtype) LOG_##logtype
#define LOG_INFO ccfuncy::LogMessage(__FILE__, __LINE__, ccfuncy::LogType::INFO)
#define LOG_DEBUG \
    ccfuncy::LogMessage(__FILE__, __LINE__, ccfuncy::LogType::DEBUG)
#define LOG_WARN ccfuncy::LogMessage(__FILE__, __LINE__, ccfuncy::LogType::WARN)
#define LOG_ERROR \
    ccfuncy::LogMessage(__FILE__, __LINE__, ccfuncy::LogType::ERROR)

// ANSI转义码宏定义
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

std::vector<string> ColorPlate{CYAN, "", YELLOW, RED};
class LogMessage;
class ConfigCentor {
   public:
    vector<Formatter*> getFormatter() { return instance->formatter; };
    void setFormatter(Formatter* formatter) {
        this->formatter.push_back(formatter);
    };
    static ConfigCentor* getInstance() {
        if (instance == nullptr) {
            instance = new ConfigCentor();
        }
        return instance;
    }

   private:
    vector<Formatter*> formatter;
    static ConfigCentor* instance;
};
ConfigCentor* ConfigCentor::instance = nullptr;

}  // namespace ccfuncy

#endif
