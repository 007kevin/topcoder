#include<bits/stdc++.h>
using namespace std;
class CubeStickers {
  public:
  string isPossible(vector <string> sticker) {
    map<string,int> m;
    for(auto &s:sticker) m[s]++;
    int cnt=0;
    for(auto &p:m) cnt+=min(2,p.second);
    return cnt>=6?"YES":"NO";
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
