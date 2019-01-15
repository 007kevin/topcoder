#include<bits/stdc++.h>
using namespace std;
class BallsConverter {
  int m[256],n;
  vector<string> convert;
  public:
  int type(int i, int j){
    return m[(int)convert[i][j]];
  }
  string theGood(vector <string> convert) {
    this->convert=convert;
    for(int i = 0; i < 26; ++i) m['A'+i]=i, m['a'+i]=26+i;
    int n=convert.size();
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        for(int k = 0; k < n; ++k)
          if(type(type(i,j),k)!=type(i,type(j,k))) return "Bad";
    return "Good";
  }
};
// BEGIN CUT HERE
int main(){ 
  return 0;
}
// END CUT HERE
