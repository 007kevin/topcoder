#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#define MAXN 6000000
int dp[MAXN];
using namespace std;
class PreprimeNumbers {
  public:
  int nthNumber(int n) {
    int cnt = 0, i = 2;
    for (; cnt < n; ++i){
      if (dp[i] == 2) cnt++; 
      if (dp[i] == 0) {
        for (int j = i; j < MAXN; j+=i){
          int k = j;
          while (k%i==0){
            k/=i;
            dp[j]++;
          }
          if (k == 1)
            dp[j]--;
        }
      }
    }
    return i-1;
  }
};
// BEGIN CUT HERE
int main(){ 
  PreprimeNumbers P;
  cout << P.nthNumber(43765) << endl;
  return 0;
}
// END CUT HERE
