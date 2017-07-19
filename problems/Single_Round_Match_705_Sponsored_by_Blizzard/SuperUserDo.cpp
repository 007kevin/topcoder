#include <iostream>
#include <string>
#include <vector>
using namespace std;
class SuperUserDo {
  public:
  int install(vector <int> A, vector <int> B) {
    int dp[1000] = {0};
    for (int i = 0; i < A.size(); ++i){
      int m_ = min(A[i],B[i]);
      int M_ = max(A[i],B[i]);
      for (int j = m_; j < M_; ++j)
        dp[j]++;
    }
    int c = 0;
    for (int i = 0; i < 1000; ++i)
      if (dp[i]) c++;
    return c;
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
