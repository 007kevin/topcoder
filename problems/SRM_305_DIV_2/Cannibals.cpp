#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int v[101][101][2];

struct state {
  int lm,lc,b,c;
  state(int lm,int lc,int b,int c)
    :lm(lm),lc(lc),b(b),c(c){}
};

class Cannibals {
  public:
  int minCrossings(int M, int C, int R) {
    queue<state> Q;
    Q.push(state(M,C,0,0));
    v[M][C][0] = 1;
    while(!Q.empty()){
      state s = Q.front(); Q.pop();
      if (s.lm == 0 && s.lc == 0 && s.b == 1){
        return s.c;
      }
      int rm = M-s.lm;
      int rc = C-s.lc;
      if (s.b == 0){
        for (int i = 1; i <= R; ++i){
          for (int j = 0; j <= i; ++j){
            int m = min(j,s.lm);
            int c = min(i-j,s.lc);
            if ((m+c==0) ||
                (m != 0 && m < c) ||
                (s.lm-m != 0 && s.lm-m < s.lc-c) ||
                (rm+m != 0 && rm+m < rc+c) ||
                v[s.lm-m][s.lc-c][1])
              continue;
            v[s.lm-m][s.lc-c][1] = 1;
            Q.push(state(s.lm-m,s.lc-c,1,s.c+1));
          }
        }
      }
      else{
        for (int i = 1; i <= R; ++i){
          for (int j = 0; j <= i; ++j){
            int m = min(j,rm);
            int c = min(i-j,rc);
            if ((m+c==0) ||
                (m != 0 && m < c) ||
                (s.lm+m != 0 && s.lm+m < s.lc+c) ||
                (rm-m != 0 && rm-m < rc-c) ||
                v[s.lm+m][s.lc+c][0])
              continue;
            v[s.lm+m][s.lc+c][0] = 1;            
            Q.push(state(s.lm+m,s.lc+c,0,s.c+1));
          }
        }
      }
    }
    return -1;
  }

};
// BEGIN CUT HERE
int main(){ 
  Cannibals C;
  cout << C.minCrossings(93, 59, 100) << endl;
  return 0;
}
// END CUT HERE
