#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  char *s;
  short i, j, n, **w;

  scanf("%hd", &n);

  s = new char[n];
  scanf("%s", s);

  w = new short*[2];
  for (i = 0; i < 2; ++i) {
    w[i] = new short[n];
    for (j = 0; j < n; ++j) {
      w[i][j] = 0;
    }
  }

  for (i = n - 1; i >= 0; --i) {
    for (j = i + 1; j < n; ++j) {
      if (s[i] == s[j]) {
        w[i % 2][j] = w[(i + 1) % 2][j - 1];
      } else {
        w[i % 2][j] = 1 + min(w[i % 2][j - 1], w[(i + 1) % 2][j]);
      }
    }
  }
  printf("%hd\n", w[0][n - 1]);

  return 0;
}
