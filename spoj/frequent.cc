#include <cstdio>
#include <algorithm>

using namespace std;

int *to_end, *to_begin, *h;

void init(int k, int b, int e) {
  if (b == e) {
    h[k] = 1;
  }
  else {
    init(2 * k, b, (b + e) / 2);
    init(2 * k + 1, (b + e) / 2 + 1, e);

    h[k] = max(
      h[2 * k],
      max(
        h[2 * k + 1],
        to_end[(b + e) / 2] - to_begin[(b + e) / 2 + 1] + 1 -
        max(b - to_begin[(b + e) / 2], 0) -
        max(to_end[(b + e) / 2] - e, 0)
      )
    );
  }
}
int query(int i, int j, int k, int b, int e) {
  if (b > j || e < i) {
    return 0;
  }

  if (b >= i && e <= j) {
    return h[k];
  }
  return max(
    query(i, j, 2 * k, b, (b + e) / 2),
    max(
      query(i, j, 2 * k + 1, (b + e) / 2 + 1, e),
      to_end[(b + e) / 2] - to_begin[(b + e) / 2 + 1] + 1 -
      max(i - to_begin[(b + e) / 2], 0) -
      max(to_end[(b + e) / 2] - j, 0)
    )
  );
}

int main() {
  int n, q, i, j, k;

  while (true) {
    scanf("%d %d", &n, &q);
    if (n == 0) {
      break;
    }
    h = new int[4 * n];
    to_end = new int[n];
    to_begin = new int[n];

    k = 0;
    for (i = 0; i < n; ++i) {
      scanf("%d", &j);
      to_begin[i] = i && k == j ? to_begin[i - 1] : i;
      k = j;
    }
    to_end[n - 1] = n - 1;
    for (i = n - 2; i >= 0; --i) {
      to_end[i] = to_begin[i] == to_begin[i + 1] ? to_end[i + 1] : i;
    }

    init(1, 0, n - 1);
    while (q--) {
      scanf("%d %d", &i, &j);
      printf("%d\n", query(i - 1, j - 1, 1, 0, n - 1));
    }

    delete[] to_end;
    delete[] to_begin;
    delete[] h;
  }

  return 0;
}
