#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ZigZag {
public:
  int longestZigZag(vector <int> s) {
    if (s.size() == 0) return 0;
    if (s.size() == 1) return 1;
    if (s.size() == 2){
      if (s[0]==s[1])
        return 1;
      return 2;
    }
    int dp[51], max = 0;
    dp[0] = 1;
    for (int i = 1; i < s.size()-1; ++i){
      if (s[i+1]-s[i]==0) continue;
      int j = i-1;
      while(j>=0&&(s[j+1]-s[j]==0||((s[i+1]-s[i])<0)==((s[j+1]-s[j])<0)))
        j--;
      if (j < 0)
        dp[i] = 1;
      else
        dp[i] = dp[j]+1;
      max = max < dp[i] ? dp[i] : max;
    }
    return max+1;
  }
};

// BEGIN CUT HERE
int main(){ 
  ZigZag t;
  
  cout << t.longestZigZag(s) << endl;
  return 0;
}
// END CUT HERE
