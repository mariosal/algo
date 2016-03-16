/*
  ID: mariosa1
  TASK: pprime
  LANG: C++11
*/
#include <cstdio>
#include <set>

static bool Palindrome(int num) {
  int reversed = 0;
  for (int i = num; i > 0; i /= 10) {
    reversed = 10 * reversed + i % 10;
  }
  return num == reversed;
}

static bool Prime(int num) {
  if (num == 1 || num % 2 == 0) {
    return false;
  }
  for (int i = 3; i * i <= num; i += 2) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

static void Check(std::set<int>* primes, int a, int b, int num) {
  if (a <= num && num <= b && Palindrome(num) && Prime(num)) {
    primes->insert(num);
  }
}

int main() {
  freopen("pprime.in", "r", stdin);
  freopen("pprime.out", "w", stdout);

  int a, b;
  scanf("%d%d", &a, &b);

  std::set<int> primes;
  for (int i = 0; i <= 9; ++i) {
    for (int j = 0; j <= 9; ++j) {
      for (int k = 0; k <= 9; ++k) {
        for (int l = 0; l <= 9; ++l) {
          for (int m = 0; m <= 9; ++m) {
            Check(&primes, a, b, i);
            Check(&primes, a, b, 10 * i + i);
            Check(&primes, a, b, 100 * i + 10 * j + i);
            Check(&primes, a, b, 1000 * i + 100 * j + 10 * j + i);
            Check(&primes, a, b, 10000 * i + 1000 * j + 100 * k + 10 * j + i);
            Check(&primes, a, b, 100000 * i + 10000 * j + 1000 * k + 100 * k +
                  10 * j + i);
            Check(&primes, a, b, 1000000 * i + 100000 * j + 10000 * k +
                  1000 * l + 100 * k + 10 * j + i);
            Check(&primes, a, b, 10000000 * i + 1000000 * j + 100000 * k +
                  10000 * l + 1000 * l + 100 * k + 10 * j + i);
            Check(&primes, a, b, 100000000 * i + 10000000 * j + 1000000 * k +
                  100000 * l + 10000 * m + 1000 * l + 100 * k + 10 * j + i);
          }
        }
      }
    }
  }

  for (auto it = primes.begin(); it != primes.end(); ++it) {
    printf("%d\n", *it);
  }
  return 0;
}
