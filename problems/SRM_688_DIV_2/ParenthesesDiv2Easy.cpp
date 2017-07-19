#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ParenthesesDiv2Easy {
  public:
  int getDepth(string s) {
    int cur = 0;
    int r = 0;
    for (int i = 0; i < s.size(); ++i)
      if (s[i] == '('){
        cur++;
        r = r < cur ? cur : r;
      }
      else
        cur--;
    return r;
  }
};
// BEGIN CUT HERE
int main(){ 
  ParenthesesDiv2Easy T;
  return 0;
}
// END CUT HERE
