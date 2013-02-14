#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  char ans, **w;
  short i, j, k, n, *a;

  scanf("%hd", &n);
  w = new char*[2];
  a = new short[n];
  for (i = 0; i < 2; ++i) {
    w[i] = new char[n];
  }

  for (i = 0; i < n; ++i) {
    scanf("%hd", a + i);
    w[0][i] = w[1][i] = 1;
  }

  for (i = 1; i < n; ++i) {
    for (j = 0; j < 2; ++j) {
      for (k = 0; k < i; ++k) {
        if (j == 0 && a[i] < a[k]) {
          w[j][i] = max((int)w[j][i], 1 + w[!j][k]);
        }
        if (j == 1 && a[i] > a[k]) {
          w[j][i] = max((int)w[j][i], 1 + w[!j][k]);
        }
      }
    }
  }

  ans = 1;
  for (i = 0; i < n; ++i) {
    ans = max(ans, w[0][i]);
    ans = max(ans, w[1][i]);
  }
  printf("%d\n", ans);

  return 0;
}
