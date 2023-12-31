/*
 * 程序名：log.cpp
 * 简介：本程序主要是为实现一个简单的日志库，目前的技术方案是仿谷歌的glog实现
 * 作者：ccfuncy
 */

#ifndef FAST_LOG_HPP
#define FAST_LOG_HPP
#include <unistd.h>

#include <chrono>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <thread>

#include "config.hpp"
using std::cout;
using std::ostream;
using std::string;
using std::stringstream;
namespace ccfuncy {
class LogMessage {
   public:
    string file;
    int level;
    int line;
    string message;
    void operator<<(const string& msg) {
        message = msg;
        auto formatter = ConfigCentor::getInstance()->getFormatter();
        for (auto& formatt : formatter) {
            formatt->outIO(this);
        }
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
}  // namespace ccfuncy

#endif  // FAST_LOG_HPP
