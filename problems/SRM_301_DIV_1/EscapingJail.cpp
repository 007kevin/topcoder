#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

class EscapingJail {
  int D[256];
  public:
  int getMaxDistance(vector <string> chain) {
    for (int i = 0; i < 10; ++i) D['0'+i] = i;
    for (int i = 0; i < 26; ++i) D['a'+i] = 10+i;
    for (int i = 0; i < 26; ++i) D['A'+i] = 36+i;
    D[' '] = INT_MAX-(61*50);
    int n = chain.size();
    int M = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i+1; j < n; ++j)
        M = max(M,sp(chain,i,j));
    return M > (61*50) ? -1 : M;
  }

  int sp(vector<string> &c, int s, int e){
    int n = c.size();
    vector<int> d(n,INT_MAX);
    vector<int> v(n,0);
    priority_queue<pii,vector<pii>,greater<pii>> Q;
    Q.push({0,s});
    d[s] = 0;
    while (!Q.empty()){
      pii p = Q.top(); Q.pop();
      if (v[p.second]) continue;
      v[p.second] = 1;
      for (int i = 0; i < n; ++i){
        if (p.first + D[c[p.second][i]] < d[i]){
          d[i] = p.first + D[c[p.second][i]];
          Q.push({d[i],i});
        }
      }
    }
    return d[e];
  }
};
// BEGIN CUT HERE
int main(){ 
  EscapingJail E;
  cout << E.getMaxDistance(
                           {"0t  ", "t0  ", "  0 ", "   0"}
                           ) << endl;
  return 0;
}
// END CUT HERE
