#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
class SpiralNumbers {
  public:
  string getPosition(ll N) {
    ll i = 1;
    ll r = 0, c = 0;
    for (;i*i < N; i+=2){
      r--;
      c++;
    }
    ll tr = i*i;
    ll tl = tr-i+1;
    ll bl = tl-i+1;
    ll br = bl-i+1;
    if (tl <= N){
      c-=tr-N;
    }
    else if (bl <= N){
      c-=tr-tl;
      r+=tl-N;
    }
    else if (br <= N){
      r+=i-1;
      c-=N-br;
    }
    else {
      r+=N-(i-2)*(i-2);
    }
    return "("+to_string(r)+","+to_string(c)+")";
  }
};
// BEGIN CUT HERE
int main(){ 
  SpiralNumbers S;
  cout << S.getPosition(1156340025) << endl;
  return 0;
}
// END CUT HERE
