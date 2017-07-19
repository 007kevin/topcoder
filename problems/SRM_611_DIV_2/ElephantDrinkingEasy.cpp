#include <iostream>
#include <string>
#include <cstring>
#include <vector>
// idea - There are 4! ways of extending elephant trunks from the sides across
//        a given grid. Since there n is at most 5, 5*5*4*4! = 4320 thus we can
//        brute force the solution.
using namespace std;
class ElephantDrinkingEasy {
  public:
  int maxElephants(vector <string> map) {
    int sol = 0;
    int x[4] = {0};
    for (int i = 0; i <= 3; ++i){
      x[i]++;
      for (int j = 0; j <= 3; ++j){
        if (x[j] == 0){
          x[j]++;
          for (int k = 0; k <= 3; ++k){
            if (x[k] == 0){
              x[k]++;
              for (int l = 0; l <= 3; ++l){
                if (x[l] == 0){
                  int cnt = 0;
                  vector<string> copy = map;
                  perf(i,copy,cnt);
                  perf(j,copy,cnt);
                  perf(k,copy,cnt);
                  perf(l,copy,cnt);
                  sol = max(sol,cnt);
                }
              }
              x[k]--;
            }
          }
          x[j]--;
        }
      }
      x[i]--;
    }
    return sol;
  }
  void perf(int i, vector<string> &map, int &cnt){
    switch(i){
    case 0:
        top(map,cnt);
      break;
    case 1:
        btm(map,cnt);
      break;
    case 2: 
        lft(map,cnt);
      break;
    case 3: 
        rgt(map,cnt);
      break;
    }
  }
  void top(vector<string> &map, int &cnt){
    int n = map.size();
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j){
        char &c = map[j][i];
        if (c!='N'){
          if (c=='Y') cnt++;
          c = 'D';          
          break;
        }
        c = 'D';
      }
  }
  void btm(vector<string> &map,int &cnt){
    int n = map.size();    
    for (int i = 0; i < n; ++i)
      for (int j = n-1; j>= 0; --j){
        char &c = map[i][j];
        if (c!='N'){
          if (c=='Y') cnt++;
          c = 'D';          
          break;
        }
        c = 'D';
      }
  }
  void lft(vector<string> &map,int &cnt){
    int n = map.size();    
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j){
        char &c = map[i][j];
        if (c!='N'){
          if (c=='Y') cnt++;
          c = 'D';
          break;
        }
        c = 'D';
      }    
  }
  void rgt(vector<string> &map,int &cnt){
    int n = map.size();    
    for (int i = 0; i < n; ++i)
      for (int j = n-1; j>= 0; --j){
        char &c = map[j][i];
        if (c!='N'){
          if (c=='Y') cnt++;
          c = 'D';          
          break;
        }
        c = 'D';
      }
  }
  
};
// BEGIN CUT HERE
int main(){ 
  ElephantDrinkingEasy E;
  cout << E.maxElephants(
                         {
  // "NYYNN",
  // "NYYNN",
  // "YNNYY",
  // "YNNYY",
  // "NYYNN"

"YYNYN",
 "NYNYY",
 "YNYYN",
 "YYNYY",
 "YYNNN"
    
                               
                           
                               }
                         ) << endl;
  return 0;
}
// END CUT HERE
