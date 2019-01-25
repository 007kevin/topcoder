#include<bits/stdc++.h>
using namespace std;
class DivideAndShift {
  public:
  int getLeast(int N, int M) {
    vector<int> subN = {1};
    int pd=2;
    while(N!=1){
      subN.push_back(N);
      while(N%pd!=0) pd++;
      N/=pd;
    }
    int dp[M+1];
    for(int i = 1; i <= M; ++i) dp[i]=M-i;
    for(int i = M; i >= 1; --i){
      for(int sub:subN){
        dp[i%sub]=min(dp[i%sub], dp[i]+1);
      }
      cout<<i<<'\t'<<dp[i]<<endl;
    }
    return dp[1];
  }
};
// BEGIN CUT HERE
int main(){ 
  DivideAndShift T;
  cout<<T.getLeast(56,14)<<endl;
  return 0;
}
// END CUT HERE
