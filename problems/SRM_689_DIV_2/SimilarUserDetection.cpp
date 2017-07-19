#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
struct cmp {
  bool operator()(string a, string b){
    for (int i = 0; i < a.size(); ++i){
      if (a[i] == '0')
        a[i] = 'O';
      if (a[i] == '1' || a[i] == 'l')
        a[i] = 'I';
    }
    for (int i = 0; i < b.size(); ++i){
      if (b[i] == '0')
        b[i] = 'O';
      if (b[i] == '1' || b[i] == 'l')
        b[i] = 'I';
    }
    return a < b;
  }
};
class SimilarUserDetection {
  public:
  string haveSimilar(vector <string> handles) {
    set<string,cmp> S;
    for (int i = 0; i < handles.size(); ++i)
      S.insert(handles[i]);
    if (S.size() == handles.size())
      return "Similar handles not found";
    return "Similar handles found";
  }
};
// BEGIN CUT HERE
int main(){ 
  SimilarUserDetection T;
  return 0;
}
// END CUT HERE
