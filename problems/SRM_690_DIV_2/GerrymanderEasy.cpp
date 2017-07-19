#include <iostream>
#include <string>
#include <vector>
using namespace std;
class GerrymanderEasy {
  public:
  double getmax(vector <int> A, vector <int> B, int K) {
    double res = 0;
    for (int i = 0; i < A.size(); ++i){
      double a = 0;
      double b = 0;
      for (int j = i; j < A.size(); ++j){
        a+=A[j];
        b+=B[j];
        if (j-i+1 >= K)
          res = res < b/a ? b/a : res;
      }
    }
    return res;
  }
};
// BEGIN CUT HERE
int main(){ 
  GerrymanderEasy T;
  return 0;
}
// END CUT HERE
