#include <iostream>
#include <vector>

using namespace std; 
  
size_t sieve(size_t n) {
  vector<bool> prime(n+1, true);
  for (size_t i = 2; i*i <= n; i++) {
    if (prime[i] == true) {
      for (int j = i * i; j < n; j += i) {
        prime[j] = false;
      }
    }
  }

  size_t sum = 0;
  for (size_t i = 2; i < prime.size(); i++) {
    if (prime[i]) {
      sum += i;
    }
  }

  return sum;
}

int main (void) { 
  cout << sieve(2000000) << endl;
  return 0;
}
