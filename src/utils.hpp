#ifndef UTILS_HPP
#define UTILS_HPP
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

namespace ccfuncy {

ofstream openFile(const string& filePath) {
    ofstream file(filePath);
    if (!file) {
        cerr << "open " << filePath << "failed!" << endl;
        exit(-1);
    }
    return file;
}

}  // namespace ccfuncy
#endif
