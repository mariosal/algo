#include <cstdio>
#include <cmath>

short loan_term;
int price, monthly_payment;

double p(double interest) {
  short i;
  double j = price;
  for (i = 1; i <= loan_term; ++i) {
    j += j * interest / 100.0;
    j -= monthly_payment;
  }
  return j;
}

double binary_search(double lo, double hi) {
  double mi, i;
  while (lo < hi) {
    mi = (lo + hi) / 2;
    i = p(mi);
    if (fabs(i) < 1e-6) {
      return mi;
    }
    if (i > 0) {
      hi = mi;
    }
    else {
      lo = mi;
    }
  }
}

int main() {
  scanf("%d %d %hd", &price, &monthly_payment, &loan_term);
  printf("%.6lf\n", 12 * binary_search(0, 100));

  return 0;
}
