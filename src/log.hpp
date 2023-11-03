/*
 * 程序名：log.cpp
 * 简介：本程序主要是为实现一个简单的日志库，目前的技术方案是仿谷歌的glog实现
 * 作者：ccfuncy
 */

#ifndef FAST_LOG_HPP
#define FAST_LOG_HPP
#include <bits/types/time_t.h>
#include <unistd.h>

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

using std::stringstream;
#include "enum.h"
#include "formattr.hpp"
using std::cout;
using std::ostream;
using std::string;
namespace ccfuncy {
BETTER_ENUM(LogType, int, INFO, DEBUG, WARN, ERROR);
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

std::vector<string> ColorPlate{"", CYAN, YELLOW, RED};

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
};
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
        : line(_line), level(_level) {
        stringstream ss(_file);
        while (std::getline(ss, file, '/'))
            ;
    };
    string formatTime() {
        auto now = std::chrono::system_clock::now();
        // 将时间点转换为time_t类型
        std::time_t current_time = std::chrono::system_clock::to_time_t(now);

        // 使用本地时间进行格式化
        std::tm* local_time = std::localtime(&current_time);

        std::stringstream ss;
        // 格式化月份和日期为两位数，并添加空格
        ss << std::setfill('0') << std::setw(2) << local_time->tm_mon + 1
           << std::setw(2) << local_time->tm_mday << " ";
        // 格式化时间为"hh:mm:ss.uuuuuu"
        ss << std::setfill('0') << std::setw(2) << local_time->tm_hour << ":"
           << std::setfill('0') << std::setw(2) << local_time->tm_min << ":"
           << std::setfill('0') << std::setw(2) << local_time->tm_sec << "."
           << std::setfill('0') << std::setw(6)
           << std::chrono::duration_cast<std::chrono::microseconds>(
                  now.time_since_epoch())
                      .count() %
                  1000000;

        return ss.str();
    }
    string getID() {
        stringstream ss;
        ss << std::setw(5) << getpid() << "." << std::setw(5)
           << std::this_thread::get_id() << " ";
        return ss.str();
    }
};
class TerminalFormatter : public Formatter {
    string format(LogMessage* msg) override {
        stringstream ss;
        ss << ColorPlate[msg->level]
           << ccfuncy::LogType::_from_index(msg->level)._to_string()[0]
           << msg->formatTime() << "   " << msg->getID() << msg->file << ":"
           << msg->line << "] " << msg->message << std::endl;
        return ss.str();
    };
};
void Init(string filepath = "") {
    auto instance = ccfuncy::ConfigCentor::getInstance();
    if (filepath != "") {
        //配置文件分支
    }
    //默认分支
    auto formatter = new TerminalFormatter();
    instance->setFormatter(formatter);
};
}  // namespace ccfuncy

#endif  // FAST_LOG_HPP
