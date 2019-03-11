/*
 * To solve this problem we used the sieve of
 * erasthotenes to generate all primes from 1 to 1000000,
 * and printed the tuple (index, prime_value) on stdout.
 * Finally, we looked for the 10001 index.
 */

#include <iostream>
#include <vector>

using namespace std;

void sieve(size_t n) {
  vector<bool> prime(n+1, true);
  for (size_t i = 2; i*i <= n; i++) {
    if (prime[i] == true) {
      for (int j = i * i; j < n; j += i) {
        prime[j] = false;
      }
    }
  }

  size_t count = 0;
  for (size_t i = 2; i < prime.size(); i++) {
    if (prime[i]) {
      cout << ++count << " ---> " << i << endl;
    }
  }
}

int main (void) {
  sieve(1000000);
  return 0;
}
