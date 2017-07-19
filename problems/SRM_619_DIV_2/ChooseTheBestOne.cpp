#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
class ChooseTheBestOne {
  public:
  int countNumber(int N) {
    int g[N], cur = 0;
    for (int i = 0; i < N; ++i)
      g[i] = i+1;
    for (int i = 1; i < N; ++i){
      cur = (cur+(((i*i)%(N-i+1))*i))%(N-i+1)-1;
      if (cur < 0) cur+=(N-i+1);
      for (int j = cur; j < N-1; ++j)
        g[j] = g[j+1];
    }
    return g[0];
  }
};
// BEGIN CUT HERE
int main(){ 
  ChooseTheBestOne C;
  cout << C.countNumber(2414) << endl; //1368
  return 0;
}
// END CUT HERE
