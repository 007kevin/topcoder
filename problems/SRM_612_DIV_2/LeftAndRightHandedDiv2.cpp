#include <iostream>
#include <string>
#include <vector>
using namespace std;
class LeftAndRightHandedDiv2 {
  public:
  int count(string S) {
    int cnt = 0;
    for (int i = 0; i < S.size()-1; ++i)
      if (S[i] == 'R' && S[i+1] == 'L')
        cnt++;
    return cnt;
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
