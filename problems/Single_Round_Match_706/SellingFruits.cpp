#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class SellingFruits {
  public:
  int maxDays(int x, int f, int d, int p) {
    if (f*x >= d)
      return d/x;
    int days = f;
    d-=f*x;
    return days+(d/(p+x));
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
