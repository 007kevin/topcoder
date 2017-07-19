#include <iostream>
#include <string>
#include <vector>
using namespace std;
class WolfCardGame {
  public:
  vector <int> createAnswer(int N, int K) {
    vector<int> s;
    if (N%2)
      for (int i = 1; i <= K; ++i)
        s.push_back(i*2);
    if (N%3)
      for (int i = 1; i <= K; ++i)
        s.push_back(i*3);
    if (N%4)
      for (int i = 1; i <= K; ++i)
        s.push_back(i*4);



      
  }
};
// BEGIN CUT HERE
int main(){ 
  WolfCardGame T;
  return 0;
}
// END CUT HERE
