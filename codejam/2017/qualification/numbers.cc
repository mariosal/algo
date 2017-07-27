#include <cinttypes>
#include <cstdio>

using namespace std;

static bool Tidy(int64_t n) {
  int64_t prev = 10;
  while (n > 0) {
    if (n % 10 > prev) {
      return false;
    }
    prev = n % 10;
    n /= 10;
  }
  return true;
}

static int64_t Exp(int64_t b, int64_t e) {
  if (e == 0) {
    return 1;
  }
  if (e % 2 == 0) {
    return Exp(b * b, e / 2);
  }
  return b * Exp(b * b, (e - 1) / 2);
}

static int64_t Digit(int64_t n, int64_t i) {
  if (i < 0) {
    return 10;
  }
  return n % Exp(10, i + 1) / Exp(10, i);
}

static int64_t Len(int64_t n) {
  int64_t ret = 0;
  while (n > 0) {
    ++ret;
    n /= 10;
  }
  return ret;
}

static int64_t Solve(int64_t n) {
  if (Tidy(n)) {
    return n;
  }
  int64_t len = Len(n);
  for (int64_t i = 0; i < len; ++i) {
    if (Digit(n, i) > Digit(n, i - 1)) {
      int64_t nines = 0;
      for (int64_t j = 0; j < i; ++j) {
        nines = 10 * nines + 9;
      }
      return Solve(n - Exp(10, i) + nines - n % Exp(10, i));
    }
  }
}

int main() {
  int max_test;
  scanf("%d", &max_test);
  for (int test = 1; test <= max_test; ++test) {
    int64_t n;
    scanf("%" PRId64, &n);
    printf("Case #%d: %" PRId64 "\n", test, Solve(n));
  }
  return 0;
}
