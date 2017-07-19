#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class SortMachine {
  public:
  int countMoves(vector <int> a) {
    int c = 0;
    vector<int> b = a;
    sort(b.begin(),b.end());
    for (int i = 0; i < a.size(); ++i)
      if (b[c] == a[i]) c++;
    return a.size()-c;
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
