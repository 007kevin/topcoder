#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
#define inf 2000000000
using namespace std;
typedef pair<int,int> pii;
class DivisorInc {
  public:
  int countOperations(int N, int M) {
    int v[100001];
    memset(v,0,sizeof(v));
    queue<pii> Q;
    Q.push({N,0});
    while (!Q.empty()){
      pii p = Q.front(); Q.pop();
      int n = p.first;
      int c = p.second;
      if (n==M) return c;
      if (v[n]) continue;
      v[n] = 1;
      for (int i = 2; i <= sqrt(n); ++i)
        if (n%i==0){
          if (n+n/i <= M) Q.push({n+n/i,c+1});
          if (n+i   <= M) Q.push({n+i,c+1});
        }
    }
    return -1;
  }
};
// BEGIN CUT HERE
int main(){ 
  DivisorInc D;
  cout << D.countOperations(4,576) << endl;
  return 0;
}
// END CUT HERE
