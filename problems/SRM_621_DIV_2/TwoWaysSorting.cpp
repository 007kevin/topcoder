#include <iostream>
#include <string>
#include <vector>
using namespace std;
class TwoWaysSorting {
  public:
  string sortingMethod(vector <string> stringList) {
    bool lex = true, len = true;
    for (int i = 0; i < stringList.size()-1; ++i){
      if (stringList[i].size() > stringList[i+1].size())
        len = false;
      if (stringList[i] > stringList[i+1])
        lex = false;
    }
    if (lex && len)
      return "both";
    if (lex)
      return "lexicographically";
    if (len)
      return "lengths";
    return "none";
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
