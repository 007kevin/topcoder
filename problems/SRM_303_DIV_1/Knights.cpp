#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
/*
  We wish to find the minimum vertex cover of graph G. Since G
  is bipartite, we can use Konig's theorem to find the maximum
  matching instead which can be done via max flow algorithm
 */
class Knights {
  public:
  int makeFriendly(int N, vector <string> pos) {
    int R[8] = {-2,-1, 1, 2, 2, 1,-1,-2};
    int C[8] = { 1, 2, 2, 1,-1,-2,-2,-1};
    int nk = 0;
    int board[N][N];
    memset(board,0,sizeof(board));
    string s;
    stringstream ss;
    for (auto str : pos) ss << str << " ";
    while (ss>>s){
      int r = stoi(s.substr(1))-1;
      int c = s[0]-'A';
      board[r][c] = ++nk;
    }
    nk+=2; // add sink and terminal nodes
    vector<vector<int>> matrix(nk,vector<int>(nk,0));
    for (int i = 0; i < N; ++i){
      for (int j = 0; j < N; ++j){
        if (board[i][j]){
          int n = board[i][j];
          
          // set up bipartition of nodes
          if ((i%2&&j%2)||(i%2==0&&j%2==0)){
            matrix[0][n] = 1;
            for (int k = 0; k < 8; ++k){
              if (0<=i+R[k]&&i+R[k]<N&&
                  0<=j+C[k]&&j+C[k]<N&&
                  board[i+R[k]][j+C[k]]){
                matrix[n][board[i+R[k]][j+C[k]]] = 1;
              }
            }
          }
          else{
            matrix[n][nk-1] = 1;
          }
        }
      }
    }

    // for (int i = 1; i < nk-1; ++i)
    //   for (int j = 1; j < i; ++j)
    //     matrix[i][j] = 0;
    // DEBUG
    /**************************/
    // for (int i = 0; i < N; ++i){
    //   for (int j = 0; j < N; ++j){
    //     cout << (board[i][j]==0?" ":to_string(board[i][j])) << " ";
    //   }
    //   cout << endl;
    // }
    // cout << "-------------------" << endl;
    // for (int i = 0; i < nk; ++i){
    //   cout << i << '\t';
    //   for (int j =0 ; j < nk; ++j){
    //     cout << matrix[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    /**************************/
    
    int m = 0;
    vector<int> v(nk,0);
    while(dfs(matrix,v,0)){
      fill(v.begin(),v.end(),0);
      m++;
    }
    return m;
  }
  
  int dfs(vector<vector<int>> &matrix, vector<int> &v, int i){
    if (v[i]) return 0;
    v[i] = 1;
    int n = matrix.size();
    if (i == n-1) return 1;
    for (int j = 0; j < n; ++j){
      if (matrix[i][j]>0 && dfs(matrix,v,j)){
        matrix[i][j]--;
        matrix[j][i]++;
        return 1;
      }
    }
    return 0;
  }
};
// BEGIN CUT HERE
int main(){ 
  Knights K;
  cout << K.makeFriendly(
                         // 5,
                         // {"A2 A4", "B1 B5", "D1 D5 E2 E4 C3"}
                         
                         // 8,
                         // {"A2 A4 A5 A6 B2 B5 B6 B7 B8",
                         //     "C3 C8 D1 D2 D3 D4 D5 D6 D8",
                         //     "E1 E3 E8 F1 F2 F8 G3 G5 H4 H7 H8"}
                         // 9,
                         // {"A3 A4 A5 A7 A8 B6 B8 C3 C6",
                         //     "C7 C9 D4 D5 D8 D9 E1 E3 E7",
                         //     "F2 G2 G6 G7 H2 H9 I2 I4 I5",
                         //     "I6 I7 I8 I9"}

26, {"A1 A2 A3 A4 A5 A6 A13 A14 A15 A19 A20 A22 A23 A24", "A25 A26 B1 B3 B4 B5 B6 B7 B9 B10 B11 B12 B14 B15", "B17 B20 B22 B25 B26 C3 C4 C5 C6 C8 C10 C13 C15 C16", "C17 C22 C23 C25 D5 D6 D9 D10 D11 D15 D18 D26 E1 E3", "E5 E7 E9 E10 E11 E12 E15 E17 E18 E19 E21 E22 E23", "E24 E25 F1 F2 F3 F4 F5 F7 F8 F9 F10 F12 F16 F17", "F18 F19 F20 F21 F22 F24 F25 G3 G4 G5 G6 G7 G8 G9", "G12 G13 G15 G17 G18 G19 G20 G21 G22 G24 G25 G26 H2", "H4 H5 H7 H10 H13 H15 H18 H20 H22 H25 I2 I3 I4 I7", "I9 I10 I12 I14 I16 I17 I18 I19 I20 I21 I24 I25 I26", "J2 J6 J8 J10 J11 J12 J13 J14 J15 J17 J18 J25 K1 K5", "K6 K8 K10 K11 K12 K15 K23 K24 K25 K26 L1 L2 L3 L7", "L8 L9 L10 L11 L14 L17 L20 L21 L25 L26 M5 M6 M7 M9", "M12 M14 M16 M22 M26 N1 N5 N10 N11 N12 N15 N16 N17", "N24 N25 O1 O3 O6 O7 O10 O13 O14 O15 O16 O17 O18", "O19 O22 O26 P2 P3 P5 P6 P7 P8 P9 P13 P16 P18 P19", "P21 P23 P24 Q3 Q4 Q7 Q8 Q10 Q12 Q13 Q15 Q17 Q18", "Q19 Q20 Q24 R2 R4 R5 R6 R10 R11 R12 R14 R15 R16", "R17 R18 R19 R21 R22 R23 R25 R26 S1 S3 S5 S6 S8 S9", "S10 S11 S13 S14 S22 S26 T2 T4 T6 T7 T11 T12 T15", "T16 T17 T18 T22 T23 T26 U2 U3 U4 U5 U8 U10 U12 U13", "U14 U15 U16 U17 U18 U21 U22 U23 U24 U25 V3 V4 V5", "V6 V8 V9 V10 V11 V12 V17 V18 V19 V20 V22 V23 V25", "V26 W1 W3 W5 W6 W9 W11 W12 W13 W15 W16 W18 W19 W20", "W21 W22 W23 W24 W26 X1 X2 X6 X8 X9 X11 X12 X13 X15", "X19 X20 X23 X25 X26 Y2 Y6 Y8 Y9 Y10 Y12 Y17 Y21", "Y23 Y25 Y26 Z1 Z2 Z3 Z4 Z5 Z6 Z7 Z8 Z9 Z12 Z13 Z15", "Z16 Z19 Z20 Z21 Z23 Z25"}
                         
                         ) << endl;
  return 0;
}
// END CUT HERE
