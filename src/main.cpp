#include <iostream>
#include <iterator>

#include "log.hpp"
using namespace std;

int main() {
    ccfuncy::Init();
    LOG(INFO) << "this is INFO msg";
    LOG(WARN) << "this is WARN msg";
    LOG(DEBUG) << "this is DEBUG msg";
    LOG(ERROR) << "this is ERROR msg";
}
