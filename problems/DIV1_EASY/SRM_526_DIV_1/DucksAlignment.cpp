#include<bits/stdc++.h>
using namespace std;
class DucksAlignment {
  public:
  int minimumTime(vector <string> grid) {
    int time=INT_MAX, n = grid.size(), m = grid[0].size();
    for(int i = 0; i < n; ++i){
      int t=0;
      vector<int> d;
      for(int j = 0; j < m; ++j)
        for(int k = 0; k < n; ++k)
          if(grid[k][j]=='o'){
            d.push_back(j);
            t+=abs(k-i);
          }
      int tt=INT_MAX;
      for(int j = 0; j < d.size(); ++j){
        int at=0;
        for(int k = 0; k < d.size(); ++k)
          at+=abs(d[j]-d[k]);
        at-=(j*(j+1))/2 + ((d.size()-j-1)*(d.size()-j))/2;
        tt=min(tt,at);
      }
      time=min(time,t+tt);
    }
    for(int j = 0; j < m; ++j){
      int t = 0;
      vector<int> d;
      for(int i = 0; i < n; ++i)
        for(int k = 0; k < m; ++k)
          if(grid[i][k]=='o'){
            t+=abs(k-j);
            d.push_back(i);
          }
      int tt=INT_MAX;
      for(int j = 0; j < d.size(); ++j){
        int at=0;
        for(int k = 0; k < d.size(); ++k)
          at+=abs(d[j]-d[k]);
        at-=(j*(j+1))/2 + ((d.size()-j-1)*(d.size()-j))/2;
        tt=min(tt,at);
      }
      time=min(time,t+tt);
    }
    return time;
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
