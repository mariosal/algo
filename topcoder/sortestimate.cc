#include <cstdio>
#include <cmath>

short c;
int time;

double binary_search(double lo, double hi) {
  double ln, mi;
  while (lo <= hi) {
    mi = (lo + hi) / 2;
    ln = log(mi) / log(2);
    if (fabs(c * mi * ln - time) < 1e-6) {
      return mi;
    }
    if (c * mi * ln < time) {
      lo = mi;
    }
    else if (c * mi * ln > time) {
      hi = mi;
    }
  }
}

int main() {
  scanf("%hd %d", &c, &time);
  printf("%.6lf\n", binary_search(0, time));

  return 0;
}
