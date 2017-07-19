#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
class IntegerPalindrome {
  int K;
  int c;
  int n;
  public:
  long long findByIndex(int K) {
    this->K = K;
    this->c = 0;
    int d = 1;
    while (gen(true,d%2?(d+1)/2:d/2,0)){
      d++;
    }
    return make_palindrome(this->n,d);
  }

  bool gen(bool f, int d, int n){
    if (d == 0){
      c++;
      if (c > K){
        this->n = n;
        return false; // stop incrementing
      }
      return true; // continue incrementing
    }
    n*=10;
    for (int i = f; i <= 9; ++i){
      if (gen(false,d-1,n+i) == false)
        return false;
    }
    return true;
  }

  long long make_palindrome(long long num, int d){
    long long orig = num;
    if (d%2) num/=10;
    int half = 0;
    while (num){
      half*=10;
      half+=num%10;
      num/=10;
    }
    return orig*pow(10,d/2)+half;
  }

};
// BEGIN CUT HERE
int main(){ 
  IntegerPalindrome P;
  cout << P.findByIndex(0) << endl;
  return 0;
}
// END CUT HERE
