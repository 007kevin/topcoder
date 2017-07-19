#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//using namespace std;
class CandidatesSelectionEasy {
  public:
  std::vector <int> sort(std::vector <std::string> score, int x) {
    std::vector<int> s(score.size());
    for (int i = 0; i < s.size(); ++i)
      s[i] = i;
    std::sort(s.begin(),s.end(),[&score,&x](const int a, const int b)->bool {
        if (score[a][x] == score[b][x]) return a < b;
        return score[a][x] < score[b][x];
      });
    return s;
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
