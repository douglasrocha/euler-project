/*
 * For this problem, we should use the arithmetic progression
 * sum formulae:
 *   a_n = a_1 + (n - 1) * d
 *     hence
 *       n = (A_n - A_1) / d + 1
 *   sum = n/2 * (2a_1 + (n - 1) * d)
 *
 * If we mix the two formulae...
 *   sum = (A_n - A_1) / (2d) * (2A_1 + A_n - A_1 - d)
 */

#include <iostream>

using namespace std;

typedef unsigned long long int ull;

ull get_arithmetic_sum (ull d, ull An) {
  return d * (An/d) * ((An / d) + 1) / 2;
}

int main(void) {
  ull s3 = get_arithmetic_sum(3, 999);
  ull s5 = get_arithmetic_sum(5, 999);
  ull s15 = get_arithmetic_sum(15, 999);
  cout << s3 + s5 - s15 << endl;
  return 0;
}
