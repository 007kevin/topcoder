#include <iostream>
#include <string>
#include <vector>
using namespace std;
class AmebaDiv2 {
  public:
  int simulate(vector <int> X, int A) {
    for (int x : X)
      if (A==x)
        A+=x;
    return A;
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
