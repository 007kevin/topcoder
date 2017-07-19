#include <iostream>
#include <string>
#include <vector>
using namespace std;
class AddMultiply {
  public:
  vector <int> makeExpression(int y) {  
    int x = y;
    while (x == y || x%5 != 0 || x/5 == 1) x++;
    return vector<int>({x/5,5,y-x});
  }
};
// BEGIN CUT HERE
int main(){ 
  AddMultiply t;
  vector<int> r = t.makeExpression(5);
    cout << r[0] << " " << r[1] << " " << r[2] << endl;
  return 0;
}
// END CUT HERE
