#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ThreeIncreasing {
  public:
  int minEaten(int a, int b, int c) {
    int eat = 0;
    if (b >= c){
      eat+=b-c+1;
      b-=b-c+1;
    }
    if (a >= b){
      eat+=a-b+1;
      a-=a-b+1;
    }
    if (a < 1 || b < 1)
      return -1;
    return eat;
      
  }

};
// BEGIN CUT HERE
int main(){ 
  ThreeIncreasing T;
  cout << T.minEaten(5,6,6) << endl;
  return 0;
}
// END CUT HERE
