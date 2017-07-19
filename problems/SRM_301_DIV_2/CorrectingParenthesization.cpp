#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <vector>
using namespace std;
class CorrectingParenthesization {
  int dp[50][50];
  
public:
  int getMinErrors(string s) {
    memset(dp,0,sizeof(dp));
    for (int i = 0; i < 50; ++i)
      for (int j = 0; j < 50; ++j)
        dp[i][j] = INT_MAX;
    return f(s,0,s.size()-1);
  }

  int f(string &s, int i, int j){
    if (i>=j)
      return 0;
    if (dp[i][j] != INT_MAX)
      return dp[i][j];
    for (int k = i+1; k <= j; k+=2)
      dp[i][j] = min(dp[i][j], f(s,i+1,k-1)+check(s,i,k)+f(s,k+1,j));
    return dp[i][j];
  }

  int check(string &s, int i, int j){
    if ((i>=j) ||
        (s[i] == '(' && s[j] == ')') ||
        (s[i] == '[' && s[j] == ']') ||
        (s[i] == '{' && s[j] == '}'))
      return 0;
    else if ((s[i] == '(' && s[j] != ')') ||
             (s[i] == '[' && s[j] != ']') ||
             (s[i] == '{' && s[j] != '}') ||
             (s[i] != '(' && s[j] == ')') ||
             (s[i] != '[' && s[j] == ']') ||
             (s[i] != '{' && s[j] == '}'))
      return 1;
    else
      return 2;
  }
  
};
// BEGIN CUT HERE
int main(){
  CorrectingParenthesization P;
  cout << P.getMinErrors("){[}](") << endl;
  cout << P.getMinErrors("([{}])()[]{}") << endl;
  cout << P.getMinErrors("([)]") << endl;
  cout << P.getMinErrors("([{}[]") << endl;     
  return 0;
}
// END CUT HERE
