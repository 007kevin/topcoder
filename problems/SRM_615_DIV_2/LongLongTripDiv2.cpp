#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
class LongLongTripDiv2 {
public:
  string isAble(long long D, long long T, long long B) {
    for (long long i = 0; i <= T; ++i)
      if (D-(B*i)-(T-i) == 0)
        return "Possible";
    return "Impossible";
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
