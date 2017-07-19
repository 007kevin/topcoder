#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class IncrementingSequence {
  public:
  string canItBeDone(int k, vector <int> A) {
    sort(A.begin(),A.end());
    for (int i = 1; i < A.size(); ++i){
      if (A[i-1] == A[i]){
        if (A[i]+k > A.size())
          return "IMPOSSIBLE";
        A[i] = A[i]+k;
        sort(A.begin()+i,A.end());
        i--;
      }
    }
    for (int i = 0; i < A.size();++i)
    if (A[i]!=i+1)
      return "IMPOSSIBLE";

    return "POSSIBLE";
  }
};
// BEGIN CUT HERE
int main(){ 
  IncrementingSequence t;
  cout << t.canItBeDone(1, {1,2,5}) << endl;
  return 0;
}
// END CUT HERE
