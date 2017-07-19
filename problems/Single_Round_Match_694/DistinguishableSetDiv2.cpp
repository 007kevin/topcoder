#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
class DistinguishableSetDiv2 {
  public:
  string sub(string a, int i){
    string s = "";
    int c = 1;
    int idx = 0;
    while (c <= i){
      if (c&i)
        s+=a[idx];
      c<<=1;
      idx++;
    }
    return s;
  }
  int count(vector <string> answer) {
    int D = 0;
    int n = answer.size();
    int m = answer[0].size();
    for (int i = 0; i < (int) pow(2,m); ++i){
      set<string> S;
      for (int j = 0; j < n; ++j){
        S.insert(sub(answer[j],i));
      }
      if (S.size() == n)
        D++;
    }
    return D;
  }
};
// BEGIN CUT HERE
int main(){ 
  DistinguishableSetDiv2 T;
  cout << T.sub("abc",7) << endl;
  return 0;
}
// END CUT HERE
