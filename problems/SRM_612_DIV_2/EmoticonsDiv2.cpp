#include <iostream>
#include <string>
#include <vector>
#include <climits>
/*
  Take note of the fact smile will be between 2 and 1000 inclusive
*/
using namespace std;
class EmoticonsDiv2 {
  public:
  int printSmiles(int s) {
    int dp[1001];
    for (int i = 0; i < 1001; ++i)
      dp[i] = INT_MAX;
    dp[1] = 0;
    for (int i = 1; i < 1001; ++i){
      int p = dp[i];
      for (int j = i; j < 1001; j+=i){
        dp[j]=min(dp[j],++p);
      }
    }
    return dp[s];
  }
};
// BEGIN CUT HERE
int main(){
  EmoticonsDiv2 T;
  
  cout << T.printSmiles(1000) << endl;
  return 0;
}
// END CUT HERE
