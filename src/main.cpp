#include <iostream>
#include <iterator>
#include <ostream>

#include "format/formatter.hpp"
#include "format/terminal_formatter.hpp"
#include "format/txt_formatter.hpp"
#include "init.hpp"
#include "utils.hpp"
using namespace std;
using namespace ccfuncy;

int main() {
    ccfuncy::Init();

    LOG(INFO) << "this is INFO msg";
    LOG(WARN) << "this is WARN msg";
    LOG(DEBUG) << "this is DEBUG msg";
    LOG(ERROR) << "this is ERROR msg";
}
