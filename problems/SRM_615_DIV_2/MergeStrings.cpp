#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
class MergeStrings {
  string dp[51][51];
  public:
  string getmin(string S, string A, string B){
    for (int i = 0; i < 51; ++i)
      for (int j = 0; j < 51; ++j)
        dp[i][j] = "0";
    string r = getmindp(S,A,B);
    return r.size() == S.size() ? r : "";
  }
  string getmindp(string S, string A, string B){
    if (S.size()==0) return "";
    int i = A.size();
    int j = B.size();
    if (dp[i][j] != "0") return dp[i][j];
    string sa="",sb="";
    if (A!=""&&(S[0]=='?'||S[0]==A[0]))
      sa=A[0]+getmindp(S.substr(1),A.substr(1),B);
    if (B!=""&&(S[0]=='?'||S[0]==B[0]))
      sb=B[0]+getmindp(S.substr(1),A,B.substr(1));
    if (sa==""&&sb=="")
      dp[i][j] = "";
    else if (sa.size() < sb.size())
      dp[i][j] = sb;
    else if (sa.size() > sb.size())
      dp[i][j] = sa;
    else
      dp[i][j] = sa<sb?sa:sb;
    return dp[i][j];
  }

};
// BEGIN CUT HERE
int main(){ 
  MergeStrings T;
  string kevin = "KEVIN";
  cout << T.getmin("???????????","AZZAA","AZAZZA" ) << endl;
  return 0;
}
// END CUT HERE
