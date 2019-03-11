/*
 * Find the largest prime factor of N = 600851475143
 * 
 * Since N is a small number, we will generate all primes
 * until sqrt(N + 1) and check to see from generated primes,
 * from highest to lower which is the first prime that divides
 * N successfully
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define N 600851475143

using namespace std;

typedef unsigned long long int ull;

vector<ull> get_all_primes_until(ull n) {
  vector<ull> output { 2, 3 };
  for (ull i = 2; i < n; i++) {
    for (ull j = 2; j*j < i; j++) {
      if (i % j == 0) {
        break;
      } else if (j + 1 > sqrt(i)) {
        output.push_back(i);
      }
    }
  }

  reverse(output.begin(), output.end());
  return output;
}

int main (void) {
  ull sqrtN = round(sqrt(N) + 1);
  vector<ull> primes = get_all_primes_until(sqrtN);

  for (auto& t : primes) {
    if (N % t == 0) {
      cout << "Found:" << endl << t << endl;
      break;
    }
  }
  
  return 0;
}
