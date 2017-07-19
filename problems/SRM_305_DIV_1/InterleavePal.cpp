#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
class InterleavePal {
  string s,t;
   int dp[51][51][51][51];
  public:
  int longestPal(string s, string t) {
    this->s = s;
    this->t = t;
    int sol = 0;
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i <= s.size(); ++i){
      for (int j = 0; j <= t.size(); ++j){
        sol = max(sol,f(i,i,j,j));
        if (i != s.size())
          sol = max(sol,f(i,i+1,j,j));
        if (j != t.size())
          sol = max(sol,f(i,i,j,j+1));
      }
    }
    return sol;
  }
  
  int f(int A, int B, int C, int D){
    if (dp[A][B][C][D] != -1)
      return dp[A][B][C][D];
    int l = (B-A)+(D-C);
    int n = s.size();
    int m = t.size();
    if (A != 0 &&
        B != n &&
        s[A-1] == s[B])
      l = max(l,f(A-1,B+1,C,D));
    if (A != 0 &&
        D != m &&
        s[A-1] == t[D])
      l = max(l,f(A-1,B,C,D+1));
    if (B != n &&
        C != 0 &&
        s[B] == t[C-1])
      l = max(l,f(A,B+1,C-1,D));
    if (C != 0 &&
        D != m &&
        t[C-1] == t[D])
      l = max(l,f(A,B,C-1,D+1));
    dp[A][B][C][D] = l;
    return l;
  }
  
};
// BEGIN CUT HERE
int main(){ 
  InterleavePal P;
  cout << P.longestPal(
                       "",
                       ""
                       ) << endl;
                       
  return 0;
}
// END CUT HERE
