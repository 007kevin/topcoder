#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class PowersOfTwo {
  long long dp[64][64];
  public:
  long long count(vector<long long> p) {
    vector<int> X(64,0);
    for (int i = 0; i < 64; ++i)
      for (int j = 0; j < 64; ++j)
        dp[i][j] = 0;
    for (int i = 0; i < p.size(); ++i)
      X[__builtin_popcountll(p[i]-1LL)]++;
    return f(X,0,0);
  }
  long long f(vector<int> &X,int k, int b){
    if (k == X.size())
      return 1;
    if (dp[k][b]!=0) return dp[k][b];
    dp[k][b]+=f(X,k+1,(X[k]+b)/2);
    if (X[k]+b>0)
      dp[k][b]+=f(X,k+1,(X[k]+b-1)/2);
    return dp[k][b];
  }
  
};
// BEGIN CUT HERE
int main(){ 
  PowersOfTwo T;
  cout << T.count({1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296, 8589934592, 17179869184, 34359738368, 68719476736, 137438953472, 274877906944, 549755813888, 1099511627776, 2199023255552, 4398046511104, 8796093022208, 17592186044416, 35184372088832, 70368744177664, 140737488355328, 281474976710656, 562949953421312}) << endl;
  return 0;
}
// END CUT HERE
