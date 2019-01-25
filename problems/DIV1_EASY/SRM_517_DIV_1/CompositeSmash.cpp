#include<bits/stdc++.h>
using namespace std;
class CompositeSmash {
  public:
  bool smash(int N, int target){
    if(N==target) return true;
    bool ok=true, prime=true;
    for(int i = 2; i*i <= N; ++i){
      if(N%i==0){
        prime=false;
        ok=ok&&(smash(i,target)||smash(N/i,target));
      }
    }
    return !prime&&ok;
  }
  string thePossible(int N, int target) {
    if(N==target) return "Yes";
    if(N%target!=0) return "No";
    for(int i = 2; i*i<=N; ++i){
      if(N%i==0){
        if(!smash(i,target)&&!smash(N/i,target)) return "No";
      }
    }
    return "Yes";
  }
};
// BEGIN CUT HERE
int main(){ 
  CompositeSmash T;
  cout<<T.thePossible(12,6)<<endl;
  return 0;
}
// END CUT HERE
