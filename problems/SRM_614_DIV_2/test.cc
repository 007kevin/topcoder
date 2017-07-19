#include <iostream>
#include <cmath>
using namespace std;

int main(){
  double r = 0;
  for(int i = 3; i <= 100; i+=2)
    r+=i*pow(0.5,i);
  cout << r << endl;
  return 0;
}
