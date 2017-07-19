#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class CostOfDancing {
  public:
  int minimum(int K, vector <int> danceCost) {
    int m = 0;
    sort(danceCost.begin(),danceCost.end());
    for (int i = 0; i < K; ++i)
      m+=danceCost[i];
    return m;
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
