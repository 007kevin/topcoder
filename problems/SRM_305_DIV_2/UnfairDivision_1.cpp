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
    int sol = 0;
    int n = assets.size();
    int sum[n];
    memset(sum,0,sizeof(sum));
    sum[0] = assets[0];
    
    for (int i = 1; i < n ; ++i){
      sum[i] = sum[i-1]+assets[i];
    }

    // Albert makes first cut between i and i+1
    for (int i = 0; i < n-1; ++i){
      // Betty makes the second cut which will maximize
      // her profits or hurt Albert at no cost
      int B = 0;
      for (int j = 0; j < n-1; ++j){
        if (i == j) continue;
        int v[3] = {sum[min(i,j)],
                    sum[max(i,j)]-sum[min(i,j)],
                    sum[n-1]-sum[max(i,j)]};
        sort(v,v+3);
        B = max(B,v[1]);
      }

      int A = INT_MAX;
      for (int j = 0; j < n-1; ++j){
        if (i == j) continue;
        int v[3] = {sum[min(i,j)],
                    sum[max(i,j)]-sum[min(i,j)],
                    sum[n-1]-sum[max(i,j)]};
        sort(v,v+3);
        if (B == v[1])
          A = min(A,v[0]);
      }
      if (A != INT_MAX)
        sol = max(A,sol);
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
