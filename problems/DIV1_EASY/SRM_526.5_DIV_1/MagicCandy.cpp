#include<bits/stdc++.h>
using namespace std;
class MagicCandy {
  public:
  int whichOne(int n) {
    if(n==1) return 1;
    int ps = 1;
    while((ps+1)*(ps+1)<n) ps++;
    if((ps+1)*(ps+1)==n) n--;
    int last=ps+1;
    while(last+ps<=n) last+=ps;
    return last;
  }
};
// BEGIN CUT HERE
int main(){ 
  MagicCandy T;
  cout<<T.whichOne(9)<<endl;
  return 0;
}
// END CUT HERE
