// NOTE: long double is required for 1.0E-9 precision!
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef pair<long long,long long> pll;
class TrainRobber {
  public:
  long double finalPosition(int length,
                       int nCarriages,
                       vector <string> offset,
                       vector <string> period,
                       long double trainSpeed,
                       long double robberSpeed,
                       int nBridges) {
    vector<pll> op; // offset pair
    istringstream ss;
    for (int i = 0; i < offset.size(); ++i){
      ss.clear();
      ss.str(offset[i]);
      int n;
      while(ss>>n)
        op.push_back(pll(n,0));
    }
    int idx = 0;
    for (int i = 0; i < period.size(); ++i){
      ss.clear();
      ss.str(period[i]);
      int n;
      while(ss>>n){
        op[idx++].second = n;
      }
    }
    priority_queue<pll,vector<pll>,greater<pll>> Q(op.begin(),op.end());
    long double rpos = 0;
    long double a = length/robberSpeed;
    while(nBridges){
      pll B = Q.top(); Q.pop();
      long double b = (B.first-rpos)/(trainSpeed+robberSpeed);
      int n = b/a;
      if (n >= nCarriages){
        return rpos+(a*nCarriages*(trainSpeed+robberSpeed));
      }
      nCarriages-=n;
      nBridges--;
      rpos = B.first;
      Q.push(pll(B.first+B.second,B.second));
    }
    return rpos;
  }
};
// BEGIN CUT HERE
int main(){
  TrainRobber T;
  // // 2862.7179487179487
  // cout << T.finalPosition(49, 29, {"516 762"}, {"4492 2855"}, 74, 78, 63) << endl;

  // // 3441.6867469879517
  // cout << T.finalPosition(49,
  //                         29,
  //                         {"516 762 678 845 321 948"},
  //                         {"4492 2855 4263 2876 4889 3504"},
  //                         93,
  //                         83,
  //                         24) << endl;

  // 999999.9999999999
  cout << T.finalPosition(1, 959375, {"1000000"}, {"1000000"}, 40027, 945253, 2) << endl;
  
  return 0;
}
// END CUT HERE
