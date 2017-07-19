#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
long long dp[1024][41][51];

class TaroCards {
  vector<int> f;
  vector<int> s;
  int K;
  int n;
  public:
  long long getNumber(vector<int> first, vector<int> second, int K) {
    memset(dp,-1,sizeof(dp));
    this->f = first;
    this->s = second;
    this->K = K;
    this->n = first.size();
    return func(0,0,0);
  }
  /*
    mask = set of numbers included from 1 to 10 
    r    = included unique numbers
    i    = current card
   */
  long long func(int mask, int r, int i){
    if (dp[mask][r][i] != -1) return dp[mask][r][i];
    if (i == n){
      dp[mask][r][i] = __builtin_popcount(mask)+r<=K?1:0;
      return dp[mask][r][i];
    }
    long long res = 0;
    // don't include this card
    res+=func(mask,r,i+1);
    // include this card
    // note: s[i] always <= 10    
    if (f[i] <= 10) res+=func(mask|1<<(s[i]-1)|1<<(f[i]-1),r,i+1);
    else res+=func(mask|1<<(s[i]-1),r+1,i+1);
    dp[mask][r][i] = res;
    return res;
  }
};
// BEGIN CUT HERE
int main(){
  TaroCards T;
  cout << T.getNumber(
{42, 32, 6, 46, 17, 35, 9, 36, 11, 10, 41, 27, 31, 44, 19, 3, 2, 47, 26, 38, 1, 24, 20, 8, 16, 33, 28, 49, 48, 50, 37, 39, 40, 5, 23, 25, 34, 21, 18, 12, 22, 15, 14, 7, 30, 43, 4, 13, 29, 45}, {10, 8, 7, 10, 4, 6, 8, 7, 7, 6, 9, 3, 6, 5, 5, 2, 7, 2, 7, 4, 4, 6, 6, 4, 3, 9, 3, 6, 4, 7, 2, 9, 7, 3, 2, 5, 7, 3, 10, 2, 6, 1, 4, 7, 5, 10, 3, 10, 4, 5}, 58
                      
                      ) << endl;

  return 0;
}
// END CUT HERE
