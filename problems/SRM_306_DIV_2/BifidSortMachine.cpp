#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class BifidSortMachine {
  public:
  int countMoves(vector <int> a) {
    vector<int> b = a;
    sort(b.begin(),b.end());
    int nm = 0;
    for (int i = 0; i < b.size(); ++i){
      int c = 0;
      for (int j = 0; j < a.size(); ++j){
        if (i+c < b.size() && b[i+c] == a[j])
          c++;
      }
      nm = max(nm,c);
    }
    return a.size()-nm;
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
