#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;

struct item {
  int w;
  double c;
  item(int w, double c):w(w),c(c){}
};
class TreasuresPacking {
  public:
  double maximizeCost(vector <string> treasures, int W) {
    istringstream ss;
    vector<item> glass;
    glass.push_back(item(0,0));
    vector<item> gold;
    for (auto s : treasures){
      int w;
      double c;
      char d;
      ss.clear();
      ss.str(s);
      ss>>w>>c>>d;
      if (d=='Y') gold.push_back(item(w,c));
      else glass.push_back(item(w,c));
    }
    sort(gold.begin(),gold.end(),[](item a, item b){
        return a.c/a.w > b.c/b.w;
      });
    double v[W+1];
    for (int i = 0; i <= W; ++i){
      double c = 0;
      int w = 0;
      for (auto a : gold){
        if (w==i) break;
        int amt = min(a.w,i-w);
        c+=(a.c/a.w)*amt;
        w+=amt;
      }
      v[i] = c;
    }
    int g = glass.size();
    double dp[W+1][g+1];
    memset(dp,0,sizeof(dp));
    double ans = 0;
    for (int i = 1; i <= W; ++i){
      for (int j = 1; j <= g; ++j){
        if (glass[j].w <= i){
          dp[i][j]=max(dp[i-glass[j].w][j-1]+glass[j].c,
                       dp[i][j-1]);
        }
        else {
          dp[i][j]=dp[i][j-1];
        }
      }
    }
    for (int i = 0; i <= W; ++i){
      ans=max(ans,dp[i][g]+v[W-i]);        
    }
    return ans;
  }
};
// BEGIN CUT HERE
int main(){ 
  TreasuresPacking T;
  // 22846.0
  cout << T.maximizeCost({"350 2765 Y", "258 560 Y", "120 9325 N", "879 302 Y",
 "611 2674 Y", "774 2273 Y", "318 1572 Y"}, 3301) << endl;
  
  return 0;
}
// END CUT HERE
