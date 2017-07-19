#include <iostream>
#include <string>
#include <vector>
using namespace std;
class SilverbachConjecture {
  public:
  vector <int> solve(int n) {
    vector<int> ret;
    int comp[2001] = {0};
    for (int i = 2; i < 2001; ++i){
      if (comp[i] == 0){
        int j = i*2;
        while (j < 2001){
          comp[j] = 1;
          j+=i;
        }
      }
    }
    for (int i = 2; i < n; ++i){
      if (comp[i]&&comp[n-i]){
        ret.push_back(i);
        ret.push_back(n-i);
        break;
      }
    }
    return ret;
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
