#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#define MODULO 1000000007
using namespace std;
int dp[51][51][51][51];
class MappingABC2 {
  int map[51];
  vector<int> t;
  public:
  int countStrings(vector <int> t) {
    this->t = t;
    memset(map,-1,sizeof(map));
    memset(dp,-1,sizeof(dp));
    return count(0,0,0,0);
  }
  int count(int i, int a, int b, int c){
    //    if (dp[i][a][b][c] != -1) return dp[i][a][b][c];//dp[i][a][b][c];
    if (i == t.size()){
      for (int j = 0; j < t.size(); ++j)
        if (map[t[j]] == 'A')
          for (int k = j+1; k < t.size(); ++k)
            if (map[t[k]] == 'B')
              for (int l = k+1; l < t.size(); ++l)
                if (map[t[l]] == 'C')
                  return 1;
      return 0;
    }
    int cnt = 0;
    if (map[t[i]] == 'A')
      cnt+=count(i+1,a+1,b,c)%MODULO;
    else if (map[t[i]] == 'B')
      cnt+=count(i+1,a,b+1,c)%MODULO;
    else if (map[t[i]] == 'C')
      cnt+=count(i+1,a,b,c+1)%MODULO;
    else{
      map[t[i]] = 'A';
      cnt+=count(i+1,a+1,b,c)%MODULO;
      map[t[i]] = 'B';
      cnt+=count(i+1,a,b+1,c)%MODULO;
      map[t[i]] = 'C';
      cnt+=count(i+1,a,b,c+1)%MODULO;
      map[t[i]] = -1;
    }
    return dp[i][a][b][c] = cnt;
  }
};
// BEGIN CUT HERE
int main(){ 
  MappingABC2 M;
  cout << M.countStrings({1,2,3}) << endl;
  cout << M.countStrings({1,2,2,1,2,1,2}) << endl;
  cout << M.countStrings({7,50,1,50,1,50,1,10,7}) << endl;
  cout << M.countStrings({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48}) << endl;
  
  
  
  return 0;
}
// END CUT HERE
