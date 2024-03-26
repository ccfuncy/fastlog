#ifndef UTILS_HPP
#define UTILS_HPP
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>

using namespace std;

namespace ccfuncy {

std::ofstream openFileForOutput(const std::string& filename) {
    // 尝试打开文件，如果失败则抛出异常
    std::ofstream fileStream;
    fileStream.open(filename, std::ios::out | std::ios::trunc);
    if (!fileStream.is_open()) {
        throw std::runtime_error("无法打开文件: " + filename);
    }
    return std::move(fileStream);
}

}  // namespace ccfuncy
#endif
