#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  short i, j, n, **a;
  int ans, **w;

#ifdef CONTEST
  freopen("triangle.in", "r", stdin);
  freopen("triangle.out", "w", stdout);
#endif

  scanf("%hd", &n);
  a = new short*[n];
  w = new int*[n];
  for (i = 0; i < n; ++i) {
    a[i] = new short[i + 1];
    w[i] = new int[i + 1]();
    for (j = 0; j <= i; ++j) {
      scanf("%hd", a[i] + j);
    }
  }

  w[0][0] = a[0][0];
  for (i = 0; i < n - 1; ++i) {
    for (j = 0; j <= i; ++j) {
      w[i + 1][j] = max(w[i + 1][j], w[i][j] + a[i + 1][j]);
      w[i + 1][j + 1] = max(w[i + 1][j + 1], w[i][j] + a[i + 1][j + 1]);
    }
  }

  ans = 0;
  for (i = 0; i < n; ++i) {
    ans = max(ans, w[n - 1][i]);
  }
  printf("%d\n", ans);

  return 0;
}
