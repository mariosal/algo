#include <cstdio>

int main() {
  const int N = 50;
  int i, j;
  long long w[N + 1];

  w[0] = 1;
  for (i = 1; i <= N; ++i) {
    w[i] = w[i - 1];
    for (j = 3; j <= i; ++j) {
      if (i - j > 2) {
        w[i] += w[i - j - 1];
      } else {
        w[i] += w[i - j];
      }
    }
  }
  printf("%lld\n", w[N]);

  return 0;
}
