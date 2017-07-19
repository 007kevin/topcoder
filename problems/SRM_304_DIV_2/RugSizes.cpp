#include <iostream>
#include <string>
#include <vector>
using namespace std;
class RugSizes {
  public:
  int rugCount(int area) {
    int cnt = 0;
    for (int i = 1; i*i <= area; ++i){
      if (area%i == 0){
        if (i!=area/i&&i%2==0&&(area/i)%2==0)
          continue;
        cnt++;
      }
    }
    return cnt;
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
