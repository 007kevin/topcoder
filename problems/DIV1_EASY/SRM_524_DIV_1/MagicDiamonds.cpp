#include<bits/stdc++.h>
using namespace std;
class MagicDiamonds {
  public:
  bool isPrime(long long n){
    for(long long i = 2; i*i <= n; ++i)
      if(n%i==0) return false;
    return true;
  }
  long long minimalTransfer(long long n) {
    if(n<=3) return n;
    if(isPrime(n)) return 2;
    return 1;
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
