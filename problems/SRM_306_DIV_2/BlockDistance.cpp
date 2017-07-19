#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define INF 10000
using namespace std;
class BlockDistance {
  string o,n;
  int dp[1000][1000];
  public:
  int minDist(vector <string> oldText, vector <string> newText) {
    o = "";
    n = "";
    for (auto s : oldText) o+=s;
    for (auto s : newText) n+=s;
    memset(dp,-1,sizeof(dp));
    int r = f(0,0);
    return r==INF?-1:r;
  }
  
  int f(int i, int j){
    if (dp[i][j] != -1) return dp[i][j];
    if (i != o.size() && j == n.size())
      return INF;
    if (i == o.size()){
      return j!=n.size();
    }
    int r = INF;
    for (int k = j; k < n.size(); ++k){
      if (o[i] == n[k])
        r = min(r,f(i+1,k+1)+(k!=j));
    }
    return dp[i][j] = r;
  }
  
};
// BEGIN CUT HERE
int main(){ 
  BlockDistance B;
  cout << B.minDist(
                    {"hello goodbye"},
                    {"hello, how are you? goodbye have a nice day"}
                    // {"aaaaaaaaaaaaaaaa"},
                    // {"aaaaaaaaaaaaaaaa","t","aaaaaaaaaaaaaaaa"}
                    ) << endl;
  return 0;
}
// END CUT HERE
