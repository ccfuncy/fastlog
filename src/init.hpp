#ifndef INIT_HPP
#define INIT_HPP
#include "format/terminal_formatter.hpp"
#include "format/txt_formatter.hpp"
#include "log.hpp"
#include "utils.hpp"
namespace ccfuncy {
void Init(string filepath, bool isfile) {
    auto instance = ccfuncy::ConfigCentor::getInstance();
    if (filepath != "") {
        //配置文件分支
    }
    //默认分支
    instance->setFormatter(new TerminalFormatter());
    if (isfile) {
        auto os = openFile("./log.txt");
        auto format = new TxtFormatter(os);
        instance->setFormatter(format);
    }
};
}  // namespace ccfuncy

#endif
