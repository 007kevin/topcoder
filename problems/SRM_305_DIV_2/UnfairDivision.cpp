#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
class UnfairDivision {
  public:
  int albertsShare(vector <int> assets) {
    int n = assets.size();
    int sol = 0;
    for (int i = 1; i < n; ++i){
      vector<int> m(3);
      for (int j = 1; j < n; ++j){
        if (i == j) continue;
        int idx = 0;
        vector<int> v(3);
        for (int k = 0; k < n; ++k){
          if (k == i || k == j)
            idx++;
          v[idx]+=assets[k];
        }
        sort(v.begin(),v.end(),greater<int>());
        swap(v[0],v[1]);
        m = max(m,v);
      }
      sol = max(sol,m[2]);
    }
    return sol;
  }
};
// BEGIN CUT HERE
int main(){ 
  UnfairDivision U;
  cout << U.albertsShare({10, 66, 62, 75, 36, 35, 76, 74, 21, 46}) << endl; // 141
    
  return 0;
}
// END CUT HERE
