#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;
class TaroFriends {
  public:
  int getNumber(vector <int> c, int X) {
    int n = c.size(), d = INT_MAX,l,r;
    if (n == 1) return 0;
    for (int i = 0; i < n; ++i){
      for (int j = i+1; j < n; ++j){
        bool a = true;
        l = min(c[i]-X,c[j]-X);
        r = max(c[i]-X,c[j]-X);
        for (int k = 0; k < n; ++k){
          if (k == i || k == j) continue;
          if (!((l<=c[k]-X && c[k]-X <= r) ||
                (l<=c[k]+X && c[k]+X <= r)))
              a = false;
        }
        if (a) d = min(d,r-l);
        a = true;
        l = min(c[i]+X,c[j]+X);
        r = max(c[i]+X,c[j]+X);
        for (int k = 0; k < n; ++k){
          if (k == i || k == j) continue;
          if (!((l<=c[k]-X && c[k]-X <= r) ||
                (l<=c[k]+X && c[k]+X <= r)))
              a = false;
        }
        if (a) d = min(d,r-l);
        a = true;
        l = min(c[i]-X,c[j]+X);
        r = max(c[i]-X,c[j]+X);
        for (int k = 0; k < n; ++k){
          if (k == i || k == j) continue;
          if (!((l<=c[k]-X && c[k]-X <= r) ||
                (l<=c[k]+X && c[k]+X <= r)))
              a = false;
        }
        if (a) d = min(d,r-l);
        a = true;
        l = min(c[i]+X,c[j]-X);
        r = max(c[i]+X,c[j]-X);
        for (int k = 0; k < n; ++k){
          if (k == i || k == j) continue;
          if (!((l<=c[k]-X && c[k]-X <= r) ||
                (l<=c[k]+X && c[k]+X <= r)))
              a = false;
        }
        if (a) d = min(d,r-l);
      }
    }
    return d;
  }
    
};
// BEGIN CUT HERE
int main(){ 
  return 0;
}
// END CUT HERE
