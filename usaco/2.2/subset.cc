/*
  ID: mariosa1
  TASK: subset
  LANG: C++11
*/
#include <cinttypes>
#include <cstdio>

int main() {
  freopen("subset.in", "r", stdin);
  freopen("subset.out", "w", stdout);

  int n;
  scanf("%d", &n);

  int64_t** ways = new int64_t*[n * (n + 1) / 4 + 1];
  for (int i = 0; i <= n * (n + 1) / 4; ++i) {
    ways[i] = new int64_t[n + 1];
  }

  ways[0][0] = 1;
  for (int i = 0; i <= n * (n + 1) / 4; ++i) {
    for (int j = 1; j <= n; ++j) {
      int64_t k = 0;
      if (i >= j) {
        k = ways[i - j][j - 1];
      }
      ways[i][j] = ways[i][j - 1] + k;
    }
  }

  if (n * (n + 1) / 2 % 2 == 1) {
    printf("0\n");
  } else {
    printf("%" PRId64 "\n", ways[n * (n + 1) / 4][n] / 2);
  }
  return 0;
}
