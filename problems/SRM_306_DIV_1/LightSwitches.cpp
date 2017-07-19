#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
class LightSwitches {
  public:
  long long countPossibleConfigurations(vector <string> switches) {
    int s = switches.size();
    int b = switches[0].size();
    int cnt = 0;
    long long M[s];
    int piv[s];
    memset(M,0,sizeof(M));
    memset(piv,0,sizeof(piv));
    for (int i = 0; i < s; ++i)
      for (int j = 0; j < b; ++j)
        if (switches[i][j] == 'Y')
          M[i]|=1LL<<j;
    for (int i = 49; i >= 0; --i){
      for (int j = 0; j < s; ++j){
        if (piv[j] == 0 && M[j]&1LL<<i){
          piv[j] = 1;
          cnt++;
          for (int k = 0; k < s; ++k)
            if (piv[k] == 0 && M[k]&1LL<<i)
              M[k]^=M[j];
          break;
        }
      }
    }
    return pow(2,cnt);
  }
};
// BEGIN CUT HERE
int main(){ 
  LightSwitches L;
  cout << L.countPossibleConfigurations(
                                        // {"YYN",
                                        //  "NNY",
                                        //  "YYY",
                                        //  "NNN"}
{"NYNYNYN",
 "YNYNYNY",
 "YYNNNYN",
 "NNNYNYN",
 "YYYYYNN",
 "YNNNNYN"}
                                        ) << endl;

  return 0;
}
// END CUT HERE
