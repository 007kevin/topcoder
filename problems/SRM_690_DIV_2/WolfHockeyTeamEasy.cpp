#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define MOD 1000000007
#define ll unsigned long long
using namespace std;
class WolfHockeyTeamEasy {
  public:
  int count(int N, int K) {
    int dp[2*N+1][2*N+1];
    memset(dp,0,sizeof(dp));
    dp[1][0] = 1;
    dp[1][1] = 1;    
    for (int x = 3; x <= 2*N-1; x+=2)
      for (int y = 0; y <= x; ++y)
        dp[x][y] = (dp[x-2][y-1]+dp[x][y-1])%MOD;

    ll res = 0;
    for (int i = K; i < 2*N-1; ++i)
      res = (res+dp[2*N-1][i])%MOD;
    for (int i = 2; i <= N; ++i)
      res = (res*i)%MOD;
    
    return (res*2)%MOD;
  }
};
// BEGIN CUT HERE
int main(){ 
  WolfHockeyTeamEasy T;
  cout << T.count(810,893) << endl;
  return 0;
}
// END CUT HERE
