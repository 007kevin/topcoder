#include<bits/stdc++.h>
using namespace std;
class CountingSeries {
  public:
  long long countThem(long long a, long long b, long long c, long long d, long long upperBound) {
    long long cnt=a<=upperBound?(upperBound-a)/b+1:0;
    for(long long i = 0; i < upperBound; ++i){
      long long cand=c*pow(d,i);
      if(cand>upperBound) break;
      if(cand>=a&&(cand-a)%b==0) {}
      else cnt++;
      if(d==1) break;
    }
    return cnt;
  }
};
// BEGIN CUT HERE
int main(){ 
  CountingSeries T;
  //                a  b  c  d      UB
  cout<<T.countThem(1,1,1,1,100000000000)<<endl;
  return 0;
}
// END CUT HERE
