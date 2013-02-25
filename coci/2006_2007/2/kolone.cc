#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  char temp, *a, *b, *c;
  int i, n, m, t, t1, t2;

  scanf("%d %d", &n, &m);
  a = new char[n + 1];
  b = new char[m + 1];
  c = new char[n + m + 1];
  scanf("%s%s%d", a, b, &t);

  for (i = 0; i < n; ++i) {
    c[n - i - 1 + min(max(t - i, 0), m)] = a[i];
  }
  for (i = 0; i < m; ++i) {
    c[n + i - min(max(t - i, 0), n)] = b[i];
  }
  c[n + m] = '\0';

  printf("%s\n", c);

  return 0;
}
