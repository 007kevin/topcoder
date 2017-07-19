#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
class NumbersChallenge {
  public:
  int MinNumber(vector <int> S) {
    set<int> s;
    for (int i = 0; i < S.size(); ++i)
      gen(s,S,i,S[i]);
    int c = 1;
    for (auto it = s.begin(); it != s.end(); ++it, ++c)
      if (c != *it)
        return c;
    return *s.end()+1;
  }
  void gen(set<int> &s, vector<int> &S, int i, int n){
    s.insert(n);
    for (int j = i+1; j < S.size(); ++j)
      gen(s,S,j,n+S[j]);
  }
};
// BEGIN CUT HERE
int main(){ 
  NumbersChallenge N;
  cout << N.MinNumber(
{883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 
442, 7064, 7, 13}
                      ) << endl;
  return 0;
}
// END CUT HERE
