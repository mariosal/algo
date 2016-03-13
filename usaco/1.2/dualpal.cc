/*
  ID: mariosa1
  TASK: dualpal
  LANG: C++11
*/
#include <cstdio>
#include <cinttypes>

static int64_t Convert(int num, int base) {
  int64_t ret = 0;
  for (int64_t ten = 1; num > 0; ten *= 10, num /= base) {
    ret += num % base * ten;
  }
  return ret;
}

static int64_t Reverse(int64_t num) {
  int64_t ret = 0;
  for (; num > 0; num /= 10) {
    ret = 10 * ret + num % 10;
  }
  return ret;
}

int main() {
  freopen("dualpal.in", "r", stdin);
  freopen("dualpal.out", "w", stdout);

  int num_palindromes, begin;
  scanf("%d%d", &num_palindromes, &begin);

  for (int i = begin + 1; num_palindromes > 0; ++i) {
    int current_palindromes = 0;
    for (int j = 2; j <= 10; ++j) {
      if (Convert(i, j) == Reverse(Convert(i, j))) {
        ++current_palindromes;
      }
    }
    if (current_palindromes >= 2) {
      printf("%d\n", i);
      --num_palindromes;
    }
  }
  return 0;
}
