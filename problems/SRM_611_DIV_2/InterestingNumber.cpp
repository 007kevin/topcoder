#include <iostream>
#include <string>
#include <vector>
using namespace std;
class InterestingNumber {
  public:
  string isInteresting(string x) {
    int D[10] = {0};
    for (int i = 0; i < x.size(); ++i){
      int n = i+1+(x[i]-'0');
      D[x[i]-'0']++;
      if (D[x[i]-'0'] == 1){
        if (n >= x.size() || x[n] != x[i]){
          return "Not interesting";
        }
      }
      if (D[x[i]-'0'] > 2)
        return "Not interesting";        
    }
	return "Interesting";
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
