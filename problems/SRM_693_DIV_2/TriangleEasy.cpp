#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#define min(a,b) ((a) < (b) ? a : b)
using namespace std;
class TriangleEasy {
  public:
  int find(int n, vector <int> x, vector <int> y) {
    int m[n][n];
    memset(m,0,sizeof(m));
    for (int i = 0; i < x.size(); ++i){
      m[x[i]][y[i]] = 1;
      m[y[i]][x[i]] = 1;
    }
    int r = 3;
    for (int i = 0; i < n; ++i)
      for (int j = i+1; j < n; ++j)
        for (int k = j+1; k < n; ++k)
          r = min(r,3-m[i][j]-m[j][k]-m[k][i]);
    return r;
  }
};
// BEGIN CUT HERE
int main(){ 
  TriangleEasy t;
  vector<int> x = {0,2};
  vector<int> y = {1,3};
  cout << t.find(4,x,y) << endl;
  return 0;
}
// END CUT HERE
