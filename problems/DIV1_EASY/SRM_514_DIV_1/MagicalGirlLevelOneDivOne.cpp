#include<bits/stdc++.h>
using namespace std;
class MagicalGirlLevelOneDivOne {
  public:
  string isReachable(vector <int> jumpTypes, int x, int y) {
    bool allOdd=true;
    for(int n:jumpTypes) allOdd=allOdd&&(n%2==1);
    return (allOdd&&abs(x%2)!=abs(y%2))?"NO":"YES";
  }
};
// BEGIN CUT HERE
int main(){ 
  MagicalGirlLevelOneDivOne T;
  cout<<T.isReachable({1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, 29, 30)<<endl;
  return 0;
}
// END CUT HERE
