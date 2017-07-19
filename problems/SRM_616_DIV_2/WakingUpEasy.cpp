#include <iostream>
#include <string>
#include <vector>
using namespace std;
class WakingUpEasy {
  public:
  int countAlarms(vector <int> volume, int S) {
    int i = 0;
    int c = 0;
    while (S>0){
      S-=volume[i];
      i=(i+1)%volume.size();
      c++;
    }
    return c;
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
