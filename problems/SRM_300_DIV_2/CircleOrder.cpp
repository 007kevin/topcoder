#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
class CircleOrder {
  public:
  bool valid_in(string &s, int i){
    int n = s.size();
    for (int j = (i+1)%n; j != i; j=(j+1)%n){
      if (islower(s[j]))
        return false;
      if (tolower(s[j]) == s[i]){
        s[j] = s[i];
        break;
      }
    }
    return true;
  }

  bool valid_out(string &s, int i){
    int n = s.size();
    for (int j = i-1<0?i-1+n:i-1; j != i; j=j-1<0?j-1+n:j-1){
      if (islower(s[j]))
        return false;
      if (tolower(s[j]) == s[i]){
        s[j] = s[i];
        break;
      }
    }
    return true;
  }
  
  string firstOrder(string circle) {
    int n = circle.size();
    int a[26];
    string ans = "";
    memset(a,-1,sizeof(a));
    for (int i = 0; i < n; ++i)
      if (islower(circle[i]))
        a[circle[i]-'a'] = i;
    for (int i = 0; i < 26; ++i){
      if (a[i] != -1){
        if (valid_in(circle,a[i]) || valid_out(circle,a[i])){
          ans+=(char)(i+'a');
          circle[a[i]] = toupper(circle[a[i]]);
          a[i] = -1;
          i = -1;
        }
      }
    }
    return ans.size() == n/2 ? ans : "NONE";
  }
  
};
// BEGIN CUT HERE
int main(){ 
  CircleOrder C;
  return 0;
}
// END CUT HERE
