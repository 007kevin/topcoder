#include <iostream>
#include <string>
#include <vector>
using namespace std;
class TaroString {
  public:
  string getAnswer(string S) {
    string s = "CAT";
    int i = 0, ctr[256] = {0};
    for (char c : S){
      if (i < 3 && s[i] == c) i++;
      ctr[(int)c]++;
    }
    if (i==3 &&
        ctr['C'] == 1 &&
        ctr['A'] == 1 &&
        ctr['T'] == 1)
      return "Possible";
    return "Impossible";
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
