#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
double P, dp[51][51][51][51];
class RandomGraph {
public:
  double probability(int n, double p) {
    P = p/1000;
    for (int i = 0; i <= 50; ++i)
      for (int j = 0; j <= 50; ++j)
        for (int k = 0; k <= 50; ++k)
          for (int l = 0; l <= 50; ++l)
            dp[i][j][k][l] = -1;
    return 1 - f(n,0,0,0);
  }

  // Note: At each recursive step, one vertex is introduced
  //       and at most 2 edges can be formed
  double f(int n,int a, int b,int c){
    if (n == 0) return 1;
    if (a < 0 || b < 0 || c < 0) return 0;
    if (dp[n][a][b][c] != -1) return dp[n][a][b][c];
    // dot
    dp[n][a][b][c] =  pow(1-P,a+b+c)*f(n-1,a+1,b,c);

    // form 2 component with 1 dot
    if (a+b+c-1 >= 0)
    dp[n][a][b][c] += pow(1-P,a+b+c-1)*P*a*f(n-1,a-1,b+2,c);

    // form 3 component from 2 dots
    if (a+b+c-2 >= 0)
    dp[n][a][b][c] += pow(1-P,a+b+c-2)*P*P*(a*(a-1)/2)*f(n-1,a-2,b,c+3);

    if (a+b+c-1 >= 0)    
    // form 3 component w/ two edges from existing 2 components
    dp[n][a][b][c] += pow(1-P,a+b+c-1)*P*(b)*f(n-1,a,b-2,c+3);

    // form 3 component w/ three edges from existing 2 components
    if (a+b+c-2 >= 0)    
    dp[n][a][b][c] += pow(1-P,a+b+c-2)*P*P*(b/2)*f(n-1,a,b-2,c+3);
    
    return dp[n][a][b][c];
  }
};
// BEGIN CUT HERE
int main(){ 
  RandomGraph R;
  cout << R.probability(50,1000) << endl;
  return 0;
}
// END CUT HERE
