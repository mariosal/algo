#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  short i, j, n, *a;
  int **w;

  scanf("%hd", &n);
  a = new short[n];
  w = new int*[n];

  for (i = 0; i < n; ++i) {
    w[i] = new int[n]();
  }
  for (i = 0; i < n; ++i) {
    scanf("%hd", a + i);
    w[i][i] = a[i];
  }

  for (i = n - 1; i >= 0; --i) {
    for (j = i; j < n; ++j) {
      w[i][j] = max((i + 1 < n ? w[i + 1][j] : 0),
                    (i + 2 < n ? w[i + 2][j] : 0) + a[i]);
    }
  }
  printf("%d\n", max(w[0][n - 2], w[1][n - 1]));

  return 0;
}
