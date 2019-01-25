#include<bits/stdc++.h>
using namespace std;
class LuckyRemainder {
  public:
  int getLuckyRemainder(string X) {
    long long int n = X.size();
    long long int ans=0;
    long long int p=1LL<<(n-1);
    
    for(int i = 0; i < X.size(); ++i)
      ans=(ans+((X[i]-'0')*p)%9)%9;

    return ans;
  }
};
// BEGIN CUT HERE
int main(){ 
  LuckyRemainder T;
  cout<<T.getLuckyRemainder("123")<<endl;
  return 0;
}
// END CUT HERE
0
