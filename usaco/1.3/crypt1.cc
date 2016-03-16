/*
  ID: mariosa1
  TASK: crypt1
  LANG: C++11
*/
#include <cstdio>
#include <set>

static int Length(int num) {
  int ret = 0;
  for (; num > 0; num /= 10) {
    ++ret;
  }
  return ret;
}

static bool Valid(const std::set<int>& digits, int num) {
  for (; num > 0; num /= 10) {
    if (digits.find(num % 10) == digits.end()) {
      return false;
    }
  }
  return true;
}

int main() {
  freopen("crypt1.in", "r", stdin);
  freopen("crypt1.out", "w", stdout);

  int num_digits;
  scanf("%d", &num_digits);

  std::set<int> digits;
  for (int i = 0; i < num_digits; ++i) {
    int digit;
    scanf("%d", &digit);
    digits.insert(digit);
  }

  int solutions = 0;
  for (int i = 100; i <= 999; ++i) {
    if (Valid(digits, i)) {
      for (int j = 10; j <= 99; ++j) {
        if (Valid(digits, j) &&
            Length(i * j) == 4 &&
            Length(i * (j / 10)) == 3 &&
            Length(i * (j % 10)) == 3) {
          if (Valid(digits, i * j) &&
              Valid(digits, i * (j / 10)) &&
              Valid(digits, i * (j % 10))) {
            ++solutions;
          }
        }
      }
    }
  }

  printf("%d\n", solutions);
  return 0;
}
