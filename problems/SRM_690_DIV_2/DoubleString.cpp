#include <iostream>
#include <string>
#include <vector>
using namespace std;
class DoubleString {
  public:
  string check(string S) {
    int n = S.size();
    if (n%2) return "not square";
    if (S.substr(0,n/2) == S.substr(n/2,n/2))
      return "square";
    return "not square";
  }
};
// BEGIN CUT HERE
int main(){ 
  DoubleString T;
  return 0;
}
// END CUT HERE
