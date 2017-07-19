#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class XBallGame {
  public:
  vector <string> newStatistics(vector <string> p) {
    for (int i = 0; i < p.size(); ++i)
      for (int j = 0; j < p[i].size(); ++j)
        if (p[i][j] == '-') p[i][j] = ' ';
    istringstream ss;
    unordered_map<string, vector<string>> H;
    for (string str : p){
      ss.str(str);
      string name, pos;
      ss >> name >> pos;
      H[name].push_back(pos);
    }
    vector<string> output;
    for (string str : p){
      ss.str(str);
      string name, pos;
      ss>>name>>pos;
      sort(H[name].begin(),H[name].end(),[&](const string &a, const string &b)->bool {
          if (a == pos) return true;
          return a < b;
        });
      name+='-';
      for (auto a : H[name])
        name+=a+',';
      output.push_back(name.substr(0,name.size()-1));
    }
    return output;
  }
};
// BEGIN CUT HERE
int main(){ 
  XBallGame X;
  vector<string> t = {"John-DH", "Jack-SP", "Sam-OF", "John-SP", "John-RP"};
  vector<string> v = X.newStatistics(t);
  for (auto s : v)
    cout << s << endl;
  return 0;
}
// END CUT HERE
