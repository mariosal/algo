#include <cstdio>

int main() {
  const int N = 50;
  int i;
  long long w[N + 1];

  w[0] = 1;
  for (i = 1; i <= N; ++i) {
    w[i] = w[i - 1] +
           (i >= 2 ? w[i - 2] : 0) +
           (i >= 3 ? w[i - 3] : 0) +
           (i >= 4 ? w[i - 4] : 0);
  }
  printf("%lld\n", w[N]);

  return 0;
}
