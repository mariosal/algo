#include <cstdio>

int main() {
  const int N = 50;
  int i, j;
  long long r[N + 1], g[N + 1], b[N + 1];

  r[0] = 1;
  for (i = 1; i <= N; ++i) {
    r[i] = r[i - 1] + (i >= 2 ? r[i - 2] : 0);
  }
  g[0] = 1;
  for (i = 1; i <= N; ++i) {
    g[i] = g[i - 1] + (i >= 3 ? g[i - 3] : 0);
  }
  b[0] = 1;
  for (i = 1; i <= N; ++i) {
    b[i] = b[i - 1] + (i >= 4 ? b[i - 4] : 0);
  }
  printf("%lld\n", r[N] + g[N] + b[N] - 3);

  return 0;
}
