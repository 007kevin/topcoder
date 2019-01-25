#include<bits/stdc++.h>
using namespace std;
class TheLotteryBothDivs {
  public:
  double find(vector <string> g) {
    set<string> d(g.begin(),g.end());
    sort(g.begin(),g.end(),greater<string>());
    for(int i = 0; i < g.size(); ++i){
      for(int j = 1; j < g[i].size(); ++j){
        string s=g[i].substr(j);
        if(d.count(s)){
          d.erase(g[i]);
          break;
        }
      }
    }
    double p=0;
    for(string s:d)
      p+=pow(0.1,s.size());
    return p;
  }
};
// BEGIN CUT HERE
int main(){
  TheLotteryBothDivs T;
  cout<<T.find({"8542861", "1954", "6", "523", "000000000", "5426", "8"})<<endl;
  return 0;
}
// END CUT HERE
