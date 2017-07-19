#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class PrimePalindromic {
public:
  int count(int A, int B) {
    int c = 0;
    for (int i = A; i <= B; ++i)
      if (pal(i)){
        c++;
      }
    return c;
  }
  
  bool pal(int n){
    int p = 2;
    vector<int> primes;
    while (n != 1){
      while (n%p) p++;
      n/=p;
      primes.push_back(p);
    }
    sort(primes.begin(),primes.end());
    int k,i;
    while (1){
      if (palindromic(primes)) return true;
      for (k = primes.size()-2; k >= 0; --k)
        if (primes[k] < primes[k+1])
          break;
      if (k < 0) break;
      for (i = primes.size()-1; i > k; --i)
        if (primes[k] < primes[i])
          break;
      swap(primes,k,i);
      int l = primes.size()-1;
      while (k < l)
        swap(primes,++k,l--);
    }
    return false;
  }

  void swap(vector<int> &v, int i , int j){
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
  }

  bool palindromic(vector<int> p){
    long long n = 0, m = 0;
    for (int i = 0; i < p.size(); ++i){
      n*=pow(10,(long long) log10(p[i]) + 1);
      n+=(long long)p[i];
    }
    for (int i = p.size() - 1; i >= 0; --i){
      while (p[i]){
        m*=10;
        m+=p[i]%10;
        p[i]/=10;
      }
    }
    return n == m;
  }
};
// BEGIN CUT HERE
int main(){
  PrimePalindromic P;
  cout << P.count(1001,2000) << endl;  
  return 0;
}
// END CUT HERE


