#include <iostream>
#include <iterator>

#include "log.hpp"
using namespace std;

int main() {
    ccfuncy::Init();
    LOG(INFO) << "hello world";
}
