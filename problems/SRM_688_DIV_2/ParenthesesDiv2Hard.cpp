#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <vector>
#define infinity UINT_MAX
#define min(a,b) ((a) < (b) ? a : b)
using namespace std;
class ParenthesesDiv2Hard {
public:
  unsigned add(unsigned a, unsigned b){
    if (a == infinity || b == infinity)
      return infinity;
    return a+b;
  }
  
  int minSwaps(string s, vector <int> L, vector <int> R) {
    int v[s.size()];
    int interval[s.size()];
    memset(v,0,sizeof(v));
    memset(interval,0,sizeof(interval));    
    string c = "";
    int open = 0;
    int close = 0;
    for (int i = 0; i < L.size(); ++i){
      c+=s.substr(L[i],R[i]-L[i]+1);
      interval[c.size()] = 1;
      for (int j = L[i]; j <= R[i]; ++j)
        v[j] = 1;
    }
    for (int i = 0; i < s.size(); ++i)
      if (v[i] == 0){
        if (s[i] == '(')
          open++;
        else
          close++;
      }
      
    unsigned dp[51][51][101];
    memset(dp,255,sizeof(dp));
    int n = c.size();
    dp[0][0][50] = 0;
    for (int i = 0; i <= n; ++i){
      for (int j = 0; j <= i; ++j){
        for (int k = -i; k <= i; ++k){
          if (interval[i] && j!=0)
            dp[i][j][50+k] = infinity;

          if (dp[i][j][50+k] != infinity){
            if (i == n){
              if (k < 0 && -k <= close)
                dp[i][0][50] = min(dp[i][j][50+k]+ -k, dp[i][0][50]);
              if (k >= 0 && k <= open)
                dp[i][0][50] = min(dp[i][j][50+k], dp[i][0][50]);
            }
            if (c[i] == '('){
              dp[i+1][j+1][50+k] = min(dp[i][j][50+k],dp[i+1][j+1][50+k]);
              if (j > 0)
                dp[i+1][j-1][50+k-1] = min(dp[i][j][50+k],dp[i+1][j-1][50+k-1]);
            }
            else {
              if (j > 0)
                dp[i+1][j-1][50+k] = min(dp[i][j][50+k],dp[i+1][j-1][50+k]);
              dp[i+1][j+1][50+k+1] = min(add(1,dp[i][j][50+k]),dp[i+1][j+1][50+k+1]);
            }
          }
        }
      }
    }
    if (dp[n][0][50] != infinity)
      return dp[n][0][50];
    else
      return -1;
  }
};

// BEGIN CUT HERE
int main(){ 
  ParenthesesDiv2Hard T;
  string s;
  vector<int> L,R;

  s = ")()()(";
  L = {0};
  R = {3};
  cout << "sol:1 " << "ans:" << T.minSwaps(s,L,R) << endl;
  
  // s = "(())";
  // L = {0,2};
  // R = {1,3};
  // cout << "sol:1 " << "ans:" << T.minSwaps(s,L,R) << endl;

  // s = "(((())";
  // L = {0,2};
  // R = {1,3};
  // cout << "sol:2 " << "ans:" << T.minSwaps(s,L,R) << endl;
  
  // s = "(((((((((";
  // L = {0,2};
  // R = {1,3};
  // cout << "sol:-1 " << "ans:" << T.minSwaps(s,L,R) << endl;
  
  s = "))()())((()()()()()())))((((((";
  L = {1,6,13,17,23,25};
  R = {4,7,16,20,24,28};
  cout << "sol:5 " << "ans:" << T.minSwaps(s,L,R) << endl;
  
  // s = "(";
  // L = {0};
  // R = {0};
  // cout << "sol:-1 " << "ans:" << T.minSwaps(s,L,R) << endl;
  
  s = ")))(()(())(()()(((()(())((()(()))))))(()()";
  L = {0, 3, 15, 28};
  R = {1, 4, 18, 39};
  cout << "sol:4 " << "ans:" << T.minSwaps(s,L,R) << endl;

  s = ")()(())()()()()(()))(())((()()(())()()(())";
  L = {16, 0};
  R = {37, 7};
  cout << "sol:2 " << "ans:" << T.minSwaps(s,L,R) << endl;
  
  return 0;
}
// END CUT HERE
