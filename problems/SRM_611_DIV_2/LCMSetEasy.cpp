#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class LCMSetEasy {
  public:
  string include(vector <int> S, int x) {
    int lcm = 1;
    for (int n:S)
      if (x%n==0)
        lcm=lcm/gcd(lcm,n)*n;
    return lcm == x ? "Possible" : "Impossible";
  }
  /* Euclidean algorithm, which uses a division algorithm 
     such as int division in combination with the observation 
     that the gcd of two numbers also divides their difference */
  int gcd(int a, int b){
    while (b!=0){
      int c = a;
      a = b;
      b = c%a;
    }
    return a;
  }
        
  
};
// BEGIN CUT HERE
int main(){ 
  LCMSetEasy T;
  cout << T.include({1, 7177955, 16, 7, 94, 31, 6456, 2, 87614, 62954, 10, 33, 6428038, 38, 8213045, 783625, 151973, 182, 977786, 868, 982, 6320, 6472099, 7516, 453, 822, 9048484, 730931, 90, 400, 210264, 1996, 89396, 1285, 29707, 34497, 819, 282014, 70555},574236400) << endl;
  return 0;
}
// END CUT HERE
