#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Taxi {
  public:
  double maxDis(long long maxX, long long maxY, long long taxiDis) {
    if (maxX + maxY < taxiDis) return -1.0;
    double sol = 0.0;
    for (long long i = 0; i <= taxiDis; ++i){
      if (i <= maxX && taxiDis-i <= maxY)
        sol=max(sol,sqrt((i*i)+((taxiDis-i)*(taxiDis-i))));
    }
    return sol;
  }
};
// BEGIN CUT HERE
int main(){ 
  Taxi T;
  cout << T.maxDis(976421, 976421, 1000000) << endl;
  return 0;
}
// END CUT HERE
