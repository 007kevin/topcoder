/*
  We had to make use of spague-grundy theory from
  combinatorial game theory :)
*/
#include <iostream>
#include <string>
#include <vector>
#define MAXN 1001
using namespace std;
class GameOfSegments {
  int dp[MAXN];
  public:
  int winner(int N) {
    // value 0 = first player lose
    // value 1 = first player win
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= N; ++i){
      int mex[i+1];
      for (int m = 0; m <= i; ++m)
        mex[m] = 0;
      for (int j = 1; j < i; ++j){
        int lower = j - 1;
        int upper = i - (j+1);
        mex[dp[lower]^dp[upper]] = 1;
      }
      int nimber = 0;
      while (mex[nimber] != 0)
        nimber++;
      dp[i] = nimber;
    }
    return dp[N] > 0 ? 1 : 2;
  }
};
// BEGIN CUT HERE
int main(){ 
  GameOfSegments test;

  return 0;
}
// END CUT HERE
