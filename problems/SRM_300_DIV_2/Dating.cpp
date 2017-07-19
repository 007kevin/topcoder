#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Dating {
  public:
  string dates(string c, int k) {
    int n = c.size();
    int s = 0;
    string ans = "";
    while (n > 1){
      s=(s+k-1)%n;
      vector<pair<char,int>> cand;
      for (int i = 0; i < n; ++i)
        if (islower(c[s]) != islower(c[i]))
          cand.push_back({c[i],i});
      if (cand.empty()) return ans != "" ? ans.substr(0,ans.size()-1) : ans;;
      sort(cand.begin(),cand.end());
      ans+=c[s];
      ans+=cand[0].first;
      ans+=" ";
      int m = min(cand[0].second,s);
      int M = max(cand[0].second,s);
      for (int i = M; i < n-1; ++i)
        c[i] = c[i+1];
      for (int i = m; i < n-1; ++i)
        c[i] = c[i+1];
      if (m < s) s--;
      n-=2;
    }
    return ans != "" ? ans.substr(0,ans.size()-1) : ans;
  }
};
// BEGIN CUT HERE
int main(){ 
  Dating D;
  cout << D.dates("abXCd",8) << endl;
  return 0;
}
// END CUT HERE
