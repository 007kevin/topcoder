#include <iostream>
#include <string>
#include <vector>
using namespace std;
class LongWordsDiv2 {
  public:
  string find(string word) {
    int N = word.size();
    for (int i = 0; i < N; ++i){
      if (i<N-1 && word[i] == word[i+1])
        return "Dislikes";
      if (!isupper(word[i]))
        return "Dislikes";
    }
    for (int i = 0; i < N; ++i)
      for (int j = i+1; j < N; ++j)
        for (int k = j+1; k < N; ++k)
          for (int l = k+1; l < N; ++l)
            if (word[i] == word[k] &&
                word[j] == word[l])
              return "Dislikes";
    return "Likes";
  }
};
// BEGIN CUT HERE
int main(){ 
  
  return 0;
}
// END CUT HERE
