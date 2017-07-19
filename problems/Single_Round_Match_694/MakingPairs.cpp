#include <iostream>
#include <string>
#include <vector>
using namespace std;
class MakingPairs {
  public:
  int get(vector <int> card) {
    int pairs = 0;
    for (int i = 0; i < card.size(); ++i)
      pairs+=card[i]/2;
    return pairs;
  }
};
// BEGIN CUT HERE
int main(){ 
  MakingPairs T;
  return 0;
}
// END CUT HERE
