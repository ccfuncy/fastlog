/*
 * 程序名：log.cpp
 * 简介：本程序主要是为实现一个简单的日志库，目前的技术方案是仿谷歌的glog实现
 * 作者：ccfuncy
 */

#ifndef FAST_LOG_HPP
#define FAST_LOG_HPP
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

using std::stringstream;
#include "enum.h"
#include "formattr.hpp"
using std::cout;
using std::ostream;
using std::string;
namespace ccfuncy {
BETTER_ENUM(LogType, int, ERROR, INFO, DEBUG);
#define LOG(logtype) LOG_##logtype
#define LOG_INFO ccfuncy::LogMessage(__FILE__, __LINE__, ccfuncy::LogType::INFO)
class LogMessage;
class ConfigCentor {
   public:
    Formatter* getFormatter() { return instance->formatter; };
    void setFormatter(Formatter* formatter) {
        instance->formatter = formatter;
    };
    static ConfigCentor* getInstance() {
        if (instance == nullptr) {
            instance = new ConfigCentor();
        }
        return instance;
    }

   private:
    Formatter* formatter;
    static ConfigCentor* instance;
};  // namespace ccfuncy
ConfigCentor* ConfigCentor::instance = nullptr;
class LogMessage {
   public:
    string file;
    int level;
    int line;
    string message;
    void operator<<(const string& msg) {
        message = msg;
        string message =
            ConfigCentor::getInstance()->getFormatter()->format(this);
        cout << message;
    }
    LogMessage(string _file, int _line, int _level)
        : file(_file), line(_line), level(_level){};
};
class TxtFormatter : public Formatter {
    string format(LogMessage* msg) override {
        stringstream ss;
        ss << "[" << ccfuncy::LogType::_from_index(msg->level)._to_string()[0]
           << "755"
           << "]" << msg->message;
        return ss.str();
    };
};
void Init(string filepath = "") {
    auto instance = ccfuncy::ConfigCentor::getInstance();
    if (filepath != "") {
        //配置文件分支
    }
    //默认分支
    auto formatter = new TxtFormatter();
    instance->setFormatter(formatter);
};
}  // namespace ccfuncy

#endif  // FAST_LOG_HPP
