#include<bits/stdc++.h>
#define LL long long int
using namespace std;
class SlimeXSlimesCity {
  public:
  int merge(vector <int> p) {
    sort(p.begin(),p.end());
    LL cnt=0, n=p.size(), tot=0;
    for(LL i = 0; i < n; ++i) tot+=p[i];
    for(LL i = 0; i < n; ++i){
      LL sum=0;
      for(LL j = i; j >= 0; --j)
        sum+=p[j];
      for(LL j = i+1; j < n; ++j)
        if(sum>=p[j]) sum+=p[j];
      if(sum==tot) cnt++;
    }
    return cnt;
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
