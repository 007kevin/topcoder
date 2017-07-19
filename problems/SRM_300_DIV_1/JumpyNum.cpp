#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int OP;
class JumpyNum {
  public:
  int howMany(int low, int high) {
    return jumpy(low,high,0,-1);
  }
  int jumpy(int low, int high, int c, int d){
    OP++;
    if (high/10 < c) return 0;
    int cnt = 0;
    c*=10;
    for (int i = 0; i < 10; ++i){
      if (abs(i-d)>1 && c+i <= high){
        if (c+i >= low)
          cnt++;
        cnt+=jumpy(low,high,c+i,i);
      }
    }
    return cnt;
  }
};
// BEGIN CUT HERE
int main(){
  JumpyNum J;
  cout << J.howMany(1,2000000000) << endl;
  cout << OP << endl;
  return 0;
}
// END CUT HERE
