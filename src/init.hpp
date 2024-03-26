#ifndef INIT_HPP
#define INIT_HPP
#include <fstream>
#include <iostream>
#include <vector>

#include "format/formatter.hpp"
#include "format/terminal_formatter.hpp"
#include "format/txt_formatter.hpp"
#include "log.hpp"
#include "utils.hpp"
namespace ccfuncy {
void Init(string filepath = "./build/log.txt", bool isfile = true) {
    auto instance = ccfuncy::ConfigCentor::getInstance();
    //默认分支
    instance->setFormatter(new TerminalFormatter());
    if (isfile) {
        std::ofstream os = openFileForOutput(filepath);
        auto format = new TxtFormatter(std::move(os));
        instance->setFormatter(format);
    }
};
}  // namespace ccfuncy

#endif
