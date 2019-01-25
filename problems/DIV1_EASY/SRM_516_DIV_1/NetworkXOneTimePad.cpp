#include<bits/stdc++.h>
#define LL long long int
using namespace std;
class NetworkXOneTimePad {
  public:
  int crack(vector <string> plaintexts, vector <string> ciphertexts) {
    int n = plaintexts[0].size(), ans =0;
    set<LL> pt,ct;
    for(auto s:plaintexts){
      LL num=0;
      for(int i = 0; i < n; ++i)
        if(s[i]=='1')
          num|=(1LL<<(n-1-i));
      pt.insert(num);
    }
    for(auto s:ciphertexts){
      LL num = 0;
      for(int i = 0; i < n; ++i)
        if(s[i]=='1')
          num|=(1LL<<(n-1-i));
      ct.insert(num);
    }
    for(auto p:pt){
      LL k = p^*ct.begin();
      LL cnt=0;
      for(auto t:pt)
        if(ct.count(k^t)) cnt++;
      if(cnt>=ct.size()) ans++;
    }
    return ans;
  }
};
// BEGIN CUT HERE
int main(){
  NetworkXOneTimePad T;
  cout<<T.crack({"110", "001"}, {"101", "010"})<<endl;
  return 0;
}
// END CUT HERE
