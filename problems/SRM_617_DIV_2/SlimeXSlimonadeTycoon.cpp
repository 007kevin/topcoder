#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class SlimeXSlimonadeTycoon {
  public:
  int sell(vector <int> m, vector <int> c, int s) {
    int N = m.size();
    int sold = 0;
    for (int i = 0; i < N; ++i){
      for (int j = max(0,i-s+1); j <= i; ++j){
        int slime = m[j];
        m[j] = max(0,slime-c[i]);
        c[i] = max(0,c[i]-slime);
        sold+=slime-m[j];
      }
    }
    return sold;
  }
};
// BEGIN CUT HERE
int main(){ 
  SlimeXSlimonadeTycoon S;
  cout << S.sell(
                 {5, 1, 1},
                 {1, 2, 3},
                 2
                 ) << "\t:" << 5 <<  endl;
  cout << S.sell(
                 {10, 20, 30},
                 {30, 20, 10},
                 1
                 ) << "\t:" << 40 <<  endl;
  cout << S.sell(
                 {1, 2, 3, 4, 5},
                 {5, 5, 5, 5, 5},
                 5
                 ) << "\t:" << 15 <<  endl;
  cout << S.sell(
                 {10000, 0, 0, 0, 0, 0, 0},
                 {1, 2, 4, 8, 16, 32, 64},
                 4
                 ) << "\t:" << 15 <<  endl;
  
  return 0;
}
// END CUT HERE
