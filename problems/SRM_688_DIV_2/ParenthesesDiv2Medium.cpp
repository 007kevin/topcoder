#include <iostream>
#include <string>
#include <vector>
#define flip(c) (c == '(' ? ')' : '(')
using namespace std;
class ParenthesesDiv2Medium {
  public:
  vector <int> correct(string s) {
    vector<int> sol;
    int d = 0;
    for (int i = 0; i < s.size(); ++i){
      if (s[i] == '(')
        d++;
      else
        d--;
      if (d < 0){
        sol.push_back(i);
        s[i] = flip(s[i]);
        d = 1;
      }
    }
    d = 0;
    for (int i = s.size()-1; i >= 0; --i){
      if (s[i] == ')')
        d++;
      else
        d--;
      if (d < 0){
        sol.push_back(i);
        s[i] = flip(s[i]);
        d = 1;
      }
    }

    return sol;
  }
};
// BEGIN CUT HERE
int main(){ 
  ParenthesesDiv2Medium T;
  vector<int> r = T.correct(")))(()(())))))");
  cout << "{ ";
  for (int i = 0; i < r.size(); ++i)
    cout << r[i] << ", ";
  cout << "}" << endl;
  cout << r.size() << endl;
  return 0;
}
// END CUT HERE
