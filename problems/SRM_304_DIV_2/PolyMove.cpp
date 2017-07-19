#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
class PolyMove {
  public:
  double addedArea(vector <int> x, vector <int> y) {
    int n = x.size();
    double z[n];
    double dp[n+1];
    memset(z,0,sizeof(z));
    memset(dp,0,sizeof(dp));
    for (int i = 0; i < n; ++i){
      int a = i==0?n-1:i-1;
      int b = (i+1)%n;
      double base = sqrt(pow(x[b]-x[a],2)+pow(y[b]-y[a],2));
      double s1   = sqrt(pow(x[i]-x[a],2)+pow(y[i]-y[a],2));
      double s2   = sqrt(pow(x[i]-x[b],2)+pow(y[i]-y[b],2));
      double peri = (base+s1+s2)/2;
      double area = sqrt(peri*(peri-base)*(peri-s1)*(peri-s2));
      double height = 2*area/base;
      z[i] = (height+1)*base/2 - area;
    }
    double M = 0;
    double f = z[0];
    dp[1] = 0;
    for (int i = 2; i <= n; ++i)
      dp[i] = max(dp[i-1],dp[i-2]+z[i-1]);
    M = max(M,dp[n]);
 
    dp[1] = f;
    z[n-1] = 0;
    for (int i = 2; i <= n; ++i)
      dp[i] = max(dp[i-1],dp[i-2]+z[i-1]);
    M = max(M,dp[n]);

    dp[1] = 0;
    for (int i = 2; i <= n; ++i)
      dp[i] = max(dp[i-1],dp[i-2]+z[i-1]);
    M = max(M,dp[n]);

    return M;
  }
};
// BEGIN CUT HERE
int main(){ 
  PolyMove P;
  cout << P.addedArea(
                      // {0,1,2},
                      // {0,1,0}
                      
                      // {0,1,1,0},
                      // {1,1,0,0}

                      // 44.79
                      // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
                      // {0, 9, 17, 24, 30, 35, 39, 42, 44, 0}

                      //                      296.18
                      {0, 50, 100, 150, 200, 200, 0},
                      {200, 202, 203, 203, 202, 0, 0}
                      ) << endl;
  return 0;
}
// END CUT HERE
