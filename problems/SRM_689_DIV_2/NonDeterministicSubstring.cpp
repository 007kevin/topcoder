#include <iostream>
#include <string>
#include <vector>
using namespace std;
class NonDeterministicSubstring {
  public:
  long long count(string& A, string& B, string b){
    for (int i = b.size(); i < B.size() && B[i] != '?' ; ++i)
      b+=B[i];
    if (b.size() == B.size()){
      if (A.find(b)!=string::npos)
        return 1;
      else
        return 0;
    }
    
    long long c = 0;
    if (A.find(b+'0')!=string::npos)
      c+=count(A,B,b+'0');
    if (A.find(b+'1')!=string::npos)
      c+=count(A,B,b+'1');
    return c;
  }
    
  long long ways(string A, string B) {
    return count(A,B,"");
  }
};
// BEGIN CUT HERE
int main(){ 
  NonDeterministicSubstring T;
  cout << T.ways("001010101100010111010","???") << endl;
  return 0;
}
// END CUT HERE
