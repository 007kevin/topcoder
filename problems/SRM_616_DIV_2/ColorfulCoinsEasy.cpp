#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class ColorfulCoinsEasy {
  public:
  string isPossible(vector <int> values) {
    vector<int> g;
    for (int i = 1; i < values.size(); ++i)
      g.push_back(values[i]/values[i-1]);
    sort(g.begin(),g.end());
    for (int i = 0; i < g.size(); ++i)
      if (g[i] <= i+1)
        return "Impossible";
    return "Possible";
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
