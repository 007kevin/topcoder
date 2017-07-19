#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
class MovingAvg {
  public:
  double difference(int k, vector <double> data) {
    double t = 0;
    double m = 1000;
    double M = 0;
    queue<double> Q;
    for (int i = 0; i <= data.size(); ++i){
      if (Q.size() == k){
        m = min(m,t/(double) k);
        M = max(M,t/(double) k);
        t-=Q.front();
        Q.pop();
      }
      if (i != data.size()){
        Q.push(data[i]);
        t+=data[i];
      }
    }
    return M - m;
  }
};
// BEGIN CUT HERE
int main(){
  MovingAvg A;
  cout << A.difference(3, {0.01, 0.02, 0.03, 0.001, 0.001}) << endl;
  return 0;
}
// END CUT HERE
