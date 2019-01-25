#include<bits/stdc++.h>
using namespace std;
class RotatedClock {
  public:
  double offset(double deg, double st){
    if(deg-st<0) return 360+deg-st;
    return deg-st;
  }
  int minutes(int hour, int min){
    return hour*60+min;
  }
  string convert(pair<int,int> time){
    string r="";
    if(time.first<10) r+='0';
    r+=to_string(time.first);
    r+=':';
    if(time.second<10) r+='0';
    r+=to_string(time.second);
    return r;
  }
  string getEarliest(int hourHand, int minuteHand) {
    double hh=hourHand, mh=minuteHand;
    vector<pair<int,int>> times;
    for(double start=0.0; start < 360.0; start+=30.0){
      double sh=offset(hh, start);
      double sm=offset(mh, start);
      for(int i = 0; i < 12; ++i){
        if((sm+(360*i))/12==sh){
          times.push_back({i,sm/6});
        }
      }
    }
    if(times.empty()) return "";
    pair<int,int> ans=times[0];
    for(auto &p:times)
      if(ans.first*60+ans.second>p.first*60+p.second) ans=p;
    return convert(ans);
  }
};
// BEGIN CUT HERE
int main(){ 
  RotatedClock T;
  cout<<T.getEarliest(1,12)<<endl;
  return 0;
}
// END CUT HERE
