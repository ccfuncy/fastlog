# fastlog
A log lib for cpp <br></br>
sample:
```
#include "log.hpp"
using namespace std;
int main() {
  ccfuncy::Init();
  LOG(INFO) << "this is INFO msg";
  LOG(WARN) << "this is WARN msg";
  LOG(DEBUG) << "this is DEBUG msg";
  LOG(ERROR) << "this is ERROR msg";
 }
```
![image](https://github.com/ccfuncy/fastlog/assets/35862080/e76a8016-d29b-4081-9548-b150e5949b53)
