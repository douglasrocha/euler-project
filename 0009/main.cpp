/*
 * Pythagorean Triplets:
 * 
 * Find the product of a,b,c such that it respects the laws:
 *   - a^2 + b^2 = c^2
 *   - a + b + c = 1000
 */

#include <iostream>

using namespace std;

typedef unsigned long long int ull;

int main (void) {
  for (ull a = 1; a <= 1000; a++) {
    for (ull b = 1; b <= 1000; b++) {
      for (ull c = 1; c <= 1000; c++) {
        if (a + b + c == 1000 && a*a + b*b == c*c) {
          cout << a * b * c << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}
