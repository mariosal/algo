#include <cstdio>

int main() {
  const int M = 50;
  int i, j, k, ans;
  long long *w;

  for (k = 3; ; ++k) {
    w = new long long[k + 1];
    w[0] = 1;
    for (i = 1; i <= k; ++i) {
      w[i] = w[i - 1];
      for (j = M; j <= i; ++j) {
        if (i - j > 2) {
          w[i] += w[i - j - 1];
        } else {
          w[i] += w[i - j];
        }
      }
    }
    if (w[k] > 1000000) {
      ans = k;
      break;
    }

    delete[] w;
  }
  printf("%d\n", ans);

  return 0;
}
