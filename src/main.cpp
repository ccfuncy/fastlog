#include <iostream>
#include <iterator>

#include "formatter/txt_formatter.hpp"
#include "log.hpp"
using namespace std;

int main() {
    auto formatter = new ccfuncy::TXTFormatter();
    ccfuncy::Init(formatter, "");
    LOG(INFO) << "this is INFO msg";
    LOG(WARN) << "this is WARN msg";
    LOG(DEBUG) << "this is DEBUG msg";
    LOG(ERROR) << "this is ERROR msg";
}
