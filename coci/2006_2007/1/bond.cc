#include <cstdio>
#include <algorithm>

using namespace std;

short n;
double *w, **a;
void memo(int k, char i) {
  if (i >= n) {
    w[k] = 1;
    return;
  }
  if (w[k] > -1) {
    return;
  }

  w[k] = 0;
  for (char j = 0; j < n; ++j) {
    if ((k & (1 << j)) == 0) {
      memo(k | (1 << j), i + 1);
      w[k] = max(w[k], a[i][j] * w[k | (1 << j)]);
    }
  }
}

int main() {
  char j;
  int i;

  scanf("%hd", &n);
  w = new double[1 << (n + 1)];
  for (i = 0; i < (1 << (n + 1)); ++i) {
    w[i] = -1;
  }

  a = new double*[n];
  for (i = 0; i < n; ++i) {
    a[i] = new double[n];
    for (j = 0; j < n; ++j) {
      scanf("%lf", a[i] + j);
      a[i][j] /= 100.0;
    }
  }
  memo(0, 0);
  printf("%.12lf\n", w[0] * 100);

  return 0;
}
