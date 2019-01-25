#include<bits/stdc++.h>
#define LL long long int
using namespace std;
class TheNumbersWithLuckyLastDigit {
  public:
  LL valid(LL &a){
    for(LL i = 0; i <= a/7; ++i)
      if((a-i*7)%4==0) return i+(a-i*7)/4;
    return 0;
  }
  LL find(LL n) {
    if(n%10==4||n%10==7) return 1;
    LL m=n-1;
    m/=100;
    m*=10;
    m+=9;
    while(m){
      LL a=n-m*pow(10,x),b;
      if(b=valid(a)) return b;
      if(m%10==0){
        m/=100;
        m*=10;
        m+=9;
        x++;
      } else
        m--;
    }
    return -1;
  }
};
// BEGIN CUT HERE
int main(){ 
  TheNumbersWithLuckyLastDigit T;
  cout<<T.find(11)<<endl;
  return 0;
}
// END CUT HERE
