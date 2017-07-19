#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
class MixingColors {
  public:
  int minColors(vector <int> colors) {
    vector<int> v(colors.size(),0);
    for (int i = 0; i < 32; ++i){
      int j = 0;
      for (;j < colors.size(); ++j)
        if (v[j] == 0 && colors[j] & (1<<i)) break;
      if (j == colors.size()) continue;
      v[j] = 1;
      for (int k = 0; k < colors.size(); ++k)
        if (v[k] == 0 && colors[k] & (1<<i))
          colors[k]^=colors[j];
    }
    int c = 0;
    for (int n : colors)
      if (n) c++;
    return c;
  }
};
// BEGIN CUT HERE
int main(){ 
  MixingColors M;
  cout << M.minColors({4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 16, 32, 64, 128, 256, 512, 1024, 2048, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 999999999, 1000000000, 15}) << endl;
  // cout << M.minColors({1,7,3,4}) << endl;

  return 0;
}
// END CUT HERE
