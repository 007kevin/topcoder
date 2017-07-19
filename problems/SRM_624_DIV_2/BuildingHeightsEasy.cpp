#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class BuildingHeightsEasy {
  public:
  int minimum(int M, vector <int> heights) {
	sort(heights.begin(),heights.end());
    int min = INT_MAX;
    for (int i = 0 ; i+M <= heights.size(); ++i){
      int cur = 0;
      for (int j = i; j < i+M; ++j)
        if (heights[j] < heights[i+M-1])
          cur+=heights[i+M-1]-heights[j];
      min = cur < min ? cur : min;
    }
    return min;
  }
};
// BEGIN CUT HERE
int main(){ 
  BuildingHeightsEasy test;
  vector<int> height = {1,3,5,2,1};
  cout << test.minimum(3,height) << endl;
  return 0;
}
// END CUT HERE
