#include <iostream>
#include <iterator>
#include <ostream>

#include "format/formatter.hpp"
#include "format/terminal_formatter.hpp"
#include "format/txt_formatter.hpp"
#include "log.hpp"
#include "utils.hpp"
using namespace std;
using namespace ccfuncy;

int main() {
    auto os = openFile("./log.txt");
    auto formatter = new TxtFormatter(os);
    vector<Formatter*> formatters;
    formatters.push_back(formatter);
    formatters.push_back(new TerminalFormatter());
    ccfuncy::Init(formatters, "");
    LOG(INFO) << "this is INFO msg";
    LOG(WARN) << "this is WARN msg";
    LOG(DEBUG) << "this is DEBUG msg";
    LOG(ERROR) << "this is ERROR msg";
}
