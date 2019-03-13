/*
 * We need to find the longest collatz sequence that starts
 * with a number less than 1M.
 * I solved this problem using memoization. I memoized the
 * number of rounds of each collatz of N calculated.
 */

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

typedef unsigned long long int ull;
map<ull, ull> memo;

ull collatz (ull n) {
  return n % 2 == 0 ? n / 2 : 3*n + 1;
}

bool is_memoized(ull n) {
  return memo.find(n) != memo.end();
}

void memoize(ull x, ull rounds) {
  memo[x] = rounds;
}

ull get_rounds (ull n) {
  ull x = n, rounds = 0;
    
  while (x > 1) {
    if (is_memoized(x)) {
      rounds += memo[x];
      break;
    }
      
    x = collatz(x);
    rounds += 1;
  }
  
  memoize(n, rounds);
  return rounds;
}

int main (void) {
  ull max = 0;
  ull max_rounds = 0;
  for (ull i = 2; i < 1000000; i++) {
    ull rounds = get_rounds(i);
    if (rounds > max_rounds) {
      max = i;
      max_rounds = rounds;
    }
  }

  cout << max << endl; 
  return 0;
}
