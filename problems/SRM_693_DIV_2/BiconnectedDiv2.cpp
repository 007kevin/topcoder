#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
class BiconnectedDiv2 {
  public:
  int minimize(vector <int> w1, vector <int> w2) {
    int n = w1.size();
    int res = w1[0]+w1[n-1];
    for (int i = 0; i < n-1; ++i) res+=w2[i];
    for (int i = 1; i < n-1; ++i) if (w1[i] < 0) res+=w1[i];
    return res;
  }
};
// BEGIN CUT HERE
int main(){ 
  BiconnectedDiv2 t;
  vector<int> w1 = {1,100,-3,2};
  vector<int> w2 = {-2,1,4};
  t.minimize(w1,w2);

}
// END CUT HERE
