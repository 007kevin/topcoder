#include <iostream>
#include <string>
#include <vector>
using namespace std;
class GoodCompanyDivTwo {
  public:
  int countGood(vector <int> superior, vector <int> workType) {
    int n = superior.size();
    int d[101][101] = {{0}};
    d[0][workType[0]]++;
    for (int i = 1; i < n; ++i){
      d[i][workType[i]]++;
      d[superior[i]][workType[i]]++;
    }
    int diverse = n;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < 101; ++j)
        if (d[i][j] > 1){
          diverse--;
          break;
        }
    return diverse;
  }
};
// BEGIN CUT HERE
int main(){ 
  GoodCompanyDivTwo G;
  cout << G.countGood(
                      {-1, 0, 1, 1, 1, 1, 2, 3, 3, 2},
                      {24, 10, 14, 39, 14, 5, 17, 6, 41, 45}
                      ) << endl;
  return 0;
}
// END CUT HERE
