
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
class MyVeryLongCake {
  public:
  int cut(int n) {
    int totient = n;
    int orig = n;
    for (int i = 2; i*i <= n; ++i){
      if (n%i==0) totient-=totient/i;
      while (n%i==0)n/=i;
    }
    if (n > 1)
      totient-=totient/n;
    return orig - totient;
  }
};
// BEGIN CUT HERE
int main(){ 
  MyVeryLongCake C;
  cout << C.cut(577007436) << endl;
  return 0;
}
// END CUT HERE
