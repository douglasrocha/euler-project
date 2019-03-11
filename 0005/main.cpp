/*
 * We should get the smallest number that can be divided
 * by all numbers from 1 to 20.
 * To solve this we reduce lcm from 20 to 1
 */

#include <iostream>

using namespace std;

typedef unsigned long long int ull; 

ull gcd (ull a, ull b) {
  return b == 0 ? a : gcd(b, a % b);
}

ull lcm (ull a, ull b) {
  return a * b / gcd(a, b);
}

int main (void) {
  ull res = 20;
  for (ull i = 19; i >= 1; i--) res = lcm(res, i);
  cout << res << endl;
  return 0;
}
