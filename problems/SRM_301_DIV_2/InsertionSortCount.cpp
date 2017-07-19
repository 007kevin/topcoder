#include <iostream>
#include <string>
#include <vector>
using namespace std;
class InsertionSortCount {
  public:
  int countMoves(vector <int> A) {
    int R[A.size()];
    int c = 0;
    for (int i = 0; i < A.size(); ++i){
      R[i] = A[i];
      int j = i;
      for (;j > 0; --j)
        if (R[j-1] < R[i])
          break;
      for (int k = i; k > j; --k){
        c++;
        R[k] = R[k-1];
      }
      R[j] = A[i];
    }
    return c;
  }
};
// BEGIN CUT HERE
int main(){ 
  InsertionSortCount I;
  cout << I.countMoves({-1000,0,1000}) << endl;
  return 0;
}
// END CUT HERE
