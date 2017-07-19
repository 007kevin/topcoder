#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int arr[5] = {3,2,4,5,1};
  sort(arr,arr+5,[](int a, int b){
      return a < b;
    });
  for (int i = 0; i < 5; ++i)
    cout << arr[i] << endl;
      
}
