#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Subsets {
  vector<int> num;
  vector<int> next;
  // next[i] returns the smallest index j such that numbers[j] != numbers[i] 
  // it is useful so that we do not try to add balls of a size that we already decided
  // to stop adding
  public:
  int findSubset(vector <int> numbers) {
    this->num = numbers;
    sort(this->num.begin(), this->num.end());
    next.resize(num.size(),num.size());
    int t = num.size();
    for (int i = num.size()-2; i >= 0; --i){
      if (num[i] != num[i+1])
        t = i+1;
      next[i] = t;
    }
    return bt(0,0,1);
  }
  int bt(int i, int s, int p){
    if (i == num.size() || s+num[i] < p*num[i])
      return s > p ? 1 : 0;
    return bt(i+1,s+num[i],p*num[i]) + bt(next[i],s,p);
  }
};
// BEGIN CUT HERE
int main(){ 
  Subsets S;
  cout << S.findSubset({1,1,1,1,2,2,2,2}) << endl;
  return 0;
}
// END CUT HERE
