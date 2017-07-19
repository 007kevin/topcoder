#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
typedef unsigned long long ull;
using namespace std;
class MovingRooksDiv2 {
  public:
  string move(vector <int> Y1, vector <int> Y2) {
    int n = Y1.size();
    ull y1 = 0, y2 = 0;
    ull bit[64] = {0};
    for (int i = 0; i < 64; ++i) bit[i] = 1ULL<<i;
    for (int i = 0; i < n; ++i) y1|=bit[i*n+Y1[i]];
    for (int i = 0; i < n; ++i) y2|=bit[i*n+Y2[i]];
    queue<ull> Q({y1});
    unordered_set<ull> V;
    while(!Q.empty()){
      ull y = Q.front(); Q.pop();
      if (y == y2)
        return "Possible";
      if (V.find(y) == V.end()){
        V.insert(y);
        for (int i = 0; i < n*n; ++i){
          if (y&bit[i]){
            for (int j = (i/n+1)*n; j < n*n; ++j){
              if (y&bit[j]){
                ull r1 = i/n, c1 = i%n;
                ull r2 = j/n, c2 = j%n;
                if (r1 < r2 && c1 > c2){
                  // swap rook positions and insert new game board
                  Q.push(y^bit[i]^bit[j]^bit[r1*n+c2]^bit[r2*n+c1]);
                }
              }
            }
          }
        }
      }
    }
    return "Impossible";
  }
};
// BEGIN CUT HERE
int main(){ 
  MovingRooksDiv2 M;
  cout << M.move(
                 {7, 6, 4, 3, 2, 1, 0, 5},
                 {5, 7, 6, 1, 0, 3, 2, 4}
                 ) << endl;
  return 0;
}
// END CUT HERE
