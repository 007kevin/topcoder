#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
class EmployManager {
  public:
  int maximumEarnings(vector <int> value, vector <string> earning) {
    int N = value.size(), e[N], profit = 0;
    
    memset(e,0,sizeof(e));
    // Initialize profit as though no employees are hired. Thus earning
    // becomes all negatives to profit
    for (int i = 0; i < N; ++i)
      for (int j = i+1; j < N; ++j)
        profit-=earning[i][j]-'0';
    
    // Sum columns of earning since that is profit gained from
    // hiring e[i].
    for (int i = 0; i < N; ++i){
      for (int j = 0; j < N; ++j)
        e[i]+=earning[j][i]-'0';
      e[i]-=value[i];
    }

    // Only hire employees in which their net profit to company is >= 0
    for (int i= 0; i < N; ++i)
      if (e[i]>0)
        profit+=e[i];
    return profit;
  }
};
// BEGIN CUT HERE
int main(){ 
  EmployManager E;
  cout << E.maximumEarnings(
                            {2, 2, 0, 1, 4, 0, 1, 0, 0, 4},
{"0100451253",  "1010518123",  "0102989242",  "0020093171",  "4590045480",  
"5189400676",  "1893500826",  "2121468008",  "5247872007",  "3321066870"}
                            // {1, 2, 3, 4},
                            // // {"0121", "1021", "2201", "1110"}
                            // {1, 1},
                            // {"02", "20"}
                            ) << endl;

  return 0;
}
// END CUT HERE
