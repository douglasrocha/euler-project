/*
 * We have to check the biggest palindrome of the product
 * of two three digit numbers. Since O(999*999) is a rather
 * small complexity, we will brute foce until we find the
 * correct answer
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main (void) {
  int old_pal = 0;
  
  for (int i = 100; i <= 999; i++) {
    for (int j = 100; j <= 999; j++) {
      if (i == j) continue;
      
      auto candidate = i * j;
      auto candidate_str = to_string(candidate);
      auto rev = candidate_str;
      reverse(rev.begin(), rev.end());
        
      if (candidate_str.compare(rev) == 0 &&
          candidate > old_pal) {
        old_pal = candidate;
      }
    }
  }

  cout << old_pal << endl;
  
  return 0;
}
