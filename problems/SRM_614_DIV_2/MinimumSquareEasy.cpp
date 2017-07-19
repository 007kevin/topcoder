#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
struct coord {
  long long x,y;
  coord():x(0),y(0){};
  coord(long long x, long long y):x(x),y(y){};
};
class MinimumSquareEasy {
  public:
  long long minArea(vector <int> x, vector <int> y) {
    long long sol = LLONG_MAX;
    int n = x.size();
    // let points i,j be ignored points
    for (int i = 0; i < n; ++i){
      for (int j = i+1; j < n; ++j){
        int s = 0;
        if (i==0)s=1;
        if (j==1)s=2;
        coord bl(x[s]-1,y[s]-1);
        coord tr(x[s]+1,y[s]+1);
        for (int k = 0; k < n; ++k){
          if (k == i || k == j) continue;
          if (x[k] <= bl.x) bl.x = x[k]-1;
          if (y[k] <= bl.y) bl.y = y[k]-1;
          if (tr.x <= x[k]) tr.x = x[k]+1;
          if (tr.y <= y[k]) tr.y = y[k]+1;
        }
        int side = max(tr.x-bl.x,tr.y-bl.y);
        sol=min(sol,(long long)side*side);
      }
    }
    return sol;
  }
};
// BEGIN CUT HERE
int main(){ 
  MinimumSquareEasy M;
  cout << M.minArea(
                    // {0, 1, 2},
                    // {0, 1, 5}

                    // {-1, -1, 0, 2, 0},
                    // {-2, -1, 0, -1, -2}

                    // {1000000000, -1000000000, 1000000000, -1000000000},
                    // {1000000000, 1000000000, -1000000000, -1000000000}

                    {1,-1,1,-1},
                    {1,1,-1,-1}
                    
                    ) << endl;
  return 0;
}
// END CUT HERE
