#include<bits/stdc++.h>
using namespace std;
class DropCoins {
public:
  int getMinimum(vector <string> board, int K) {
    int n = board.size(),m=board[0].size(), ans=INT_MAX;
    for(int r = 1; r <= n; ++r){
      for(int c = 1; c <= m; ++c){
        if(r*c<K) continue;
        for(int i = r; i <= n; ++i){
          for(int j = c; j <= m; ++j){
            int coins=0;
            for(int x=i-r; x < i; ++x)
              for(int y = j-c; y < j; ++y)
                if(board[x][y]=='o') coins++;
            if(coins==K){
              //FINISH HERE
              ans=min(ans,
                      min(i-r,n-i)*2+max(i-r,n-i)+
                      min(j-c,m-j)*2+max(j-c,m-j));
            }
          }
        }
      }
    }
    return ans==INT_MAX?-1:ans;
  }
};
// BEGIN CUT HERE
int main(){
  DropCoins T;
  cout<<T.getMinimum(
                     {".o.."
                      ,"oooo"
                      ,"..o."}
                     , 3)<<endl;
  return 0;
}
// END CUT HERE
