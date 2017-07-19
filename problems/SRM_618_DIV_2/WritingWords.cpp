#include <iostream>
#include <string>
#include <vector>
using namespace std;
class WritingWords {
  public:
  int write(string word) {
    int c = 0;
    for (char l : word)
      c+=l-'A'+1;
    return c;
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
