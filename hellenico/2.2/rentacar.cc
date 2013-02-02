#include <cstdio>
#include <algorithm>

using namespace std;

struct Time {
  int a, t;
};
bool operator<(Time a, Time b) {
  if (a.t == b.t) {
    return a.a < b.a;
  }
  return a.t < b.t;
}

int main() {
  short n, i, j, *w, *q;
  Time *car;

#ifdef CONTEST
  freopen("rentacar.in", "r", stdin);
  freopen("rentacar.out", "w", stdout);
#endif

  scanf("%hd", &n);
  q = new short[n + 1]();
  w = new short[n + 1]();
  car = new Time[n];

  for (i = 0; i < n; ++i) {
    scanf("%*d %d %d", &car[i].a, &car[i].t);
  }
  sort(car, car + n);

  for (i = 0; i < n; ++i) {
    for (j = i - 1; j >= 0; --j) {
      if (car[j].t <= car[i].a) {
        q[i + 1] = j + 1;
        break;
      }
    }
  }

  w[0] = 0;
  for (i = 1; i <= n; ++i) {
    w[i] = max(short(1 + w[q[i]]), w[i - 1]);
  }
  printf("%hd\n", w[n]);

  return 0;
}
