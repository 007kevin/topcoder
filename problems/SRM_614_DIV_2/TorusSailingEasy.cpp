#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>
#include <float.h>
using namespace std;
class TorusSailingEasy {
public:
  double expectedTime(int N, int M, int goalX, int goalY) {
    double sol = 0;
    int x=0,y=0,g=0,n=0;
    while(n==0 || !(x==0 && y==0)){
      if (x==goalX && y == goalY) g = n;
      x=(x+1)%N;
      y=(y+1)%M;
      n++;
    }
    if (g==0) return -1;
    return (n-g)*g; // <- Use the concept of 'hitting time' from
                    //    probability theory. Study up on how
                    //    this formula gives the expected number of
                    //    days to reach goal node
  }
};
// BEGIN CUT HERE
int main(){ 
  TorusSailingEasy T;
  cout << T.expectedTime(4,6,1,3) << endl;
  return 0;
}
// END CUT HERE
