#include <iostream>
#include <string>
#include <vector>
using namespace std;
class MicroStrings {
  public:
  string makeMicroString(int A, int D) {
    string r = "";
    while(A>=0){
      r+=to_string(A);
      A-=D;
    }
    return r;
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
