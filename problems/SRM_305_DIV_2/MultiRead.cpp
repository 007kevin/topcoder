#include <iostream>
#include <string>
#include <vector>
using namespace std;
class MultiRead {
  public:
  int minCycles(string trace, int procs) {
    int c = 0;
    int r = 0;
    for (int i = 0; i < trace.size(); ++i){
      if (trace[i] == 'W'){
        c+=(r/procs)+(r%procs?1:0);
        c++;
        r = 0;
      }
      else {
        r++;
      }
    }
    c+=(r/procs)+(r%procs?1:0);
    return c;
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
