#include<bits/stdc++.h>
#define MOD 1000000009
#define LL long long int
using namespace std;
class YetAnotherIncredibleMachine {
  public:
  int countWays(vector <int> platformMount, vector <int> platformLength, vector <int> balls) {
    LL n = platformMount.size(), ans=1;
    vector<LL> lb(n,-50001), rb(n,50001);
    for(LL i = 0; i < n; ++i){
      for(LL j = 0; j < balls.size(); ++j){
        if(balls[j]<=platformMount[i]) lb[i]=max(lb[i],(LL)balls[j]);
        if(balls[j]>=platformMount[i]) rb[i]=min(rb[i],(LL)balls[j]);
      }
    }
    for(LL i = 0; i < n; ++i){
      LL dist=(min(rb[i]-1, (LL) platformMount[i]+platformLength[i]) -
               max(lb[i]+1,(LL) platformMount[i]-platformLength[i])) - platformLength[i]+1;
      dist=max(0LL,dist);
      dist%=MOD;
      ans=(ans*dist)%MOD;
    }
    return ans;
  }
};
// BEGIN CUT HERE
int main(){ 
  YetAnotherIncredibleMachine T;
  cout<<T.countWays({100, -4215, 251},{400, 10000, 2121},{5000, 2270, 8512, 6122})<<endl;
  return 0;
}

// END CUT HERE
