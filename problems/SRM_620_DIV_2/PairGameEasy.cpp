#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
class PairGameEasy {
  int dp[1001][1001];
  public:
  string able(int a, int b, int c, int d) {
    memset(dp,-1,sizeof(dp));
    return f(a,b,c,d) ? "Able to generate" : "Not able to generate";
  }

  int f(int a, int b, int c, int d){
    if (a == c && b == d) return 1;
    if (a > c || b > d) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    return (dp[a][b] = f(a+b,b,c,d) | f(a,a+b,c,d));
  }
};
// BEGIN CUT HERE
int main(){ 
  PairGameEasy P;
  cout << P.able(7, 1, 489, 948) << endl;
  return 0;
}
// END CUT HERE
