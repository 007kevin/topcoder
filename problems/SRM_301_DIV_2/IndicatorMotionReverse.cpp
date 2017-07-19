#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class IndicatorMotionReverse {
  public:
  string getMinProgram(vector<string> actions) {
    string s;
    ostringstream ss;
    for (string str : actions)
      ss<<str;
    s = ss.str();
    if (s.size() == 1)
      return "";
    if (s.size() == 2){
      ss.str("");
      ss<<eval(s[0],s[1])<<"01";
      return ss.str();
    }
    
    vector<pair<char,int>> A;
    A.push_back({eval(s[0],s[1]),1});
    for (int i = 1; i < s.size()-1; ++i){
      auto last = A.rbegin();
      char m = eval(s[i],s[i+1]);
      if (m == last->first)
        last->second++;
      else
        A.push_back({m,1});
    }
    
    ss.str("");
    for (auto p : A){
      int r = p.second%99;
      if (r != 0)
        ss<<p.first+(r<10?"0"+to_string(r):to_string(r));
      for (int i = 0; i < p.second/99; ++i)
        ss<<p.first+to_string(99);
    }
    string sol = ss.str();
    return sol.size() < 100 ? sol : sol.substr(0,97)+"...";
  }
  char eval(char a, char b){
    if (a == b)
      return 'S';
    if ((a == '|' && b == '/') ||
        (a == '/' && b == '-') ||
        (a == '-' && b == 'N') ||
        (a == 'N' && b == '|') ||
        (a == '|' && b == '/') ||
        (a == '/' && b == '-') ||
        (a == '-' && b == 'N') ||
        (a == 'N' && b == '|'))
      return 'R';
    if ((a == '|' && b == 'N') ||
        (a == 'N' && b == '-') ||
        (a == '-' && b == '/') ||
        (a == '/' && b == '|') ||
        (a == '|' && b == 'N') ||
        (a == 'N' && b == '-') ||
        (a == '-' && b == '/') ||
        (a == '/' && b == '|'))
      return 'L';
    return 'F';
  }
};
// BEGIN CUT HERE
int main(){
  IndicatorMotionReverse I;
  cout << I.getMinProgram(
                          {"NN"}

) << endl;
  return 0;
}
// END CUT HERE
