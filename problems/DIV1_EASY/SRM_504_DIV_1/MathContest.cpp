#include<bits/stdc++.h>
using namespace std;
class MathContest {
  public:
  int countBlack(string ballSequence, int repetitions) {
    string s="";
    while(repetitions--) s+=ballSequence;
    
    char blk='B';
    int i = 0, j = s.size()-1, dir=1, b=0;
    while(i<=j){
      char c;
      if(dir==1) c=s[i++];
      else c=s[j--];
      if(c==blk) b++, blk=blk=='B'?'W':'B';
      else dir=dir==1?0:1;
    }
    return b;
  }
};
// BEGIN CUT HERE
int main(){ 
  MathContest T;
  cout<<T.countBlack("BW", 10)<<endl;
  return 0;
}
// END CUT HERE
