#include <cstdio>
#include <algorithm>

using namespace std;

void add(long long *tree, int p, int n, int v) {
  while (p <= n) {
    tree[p] += v;
    p += p & -p;
  }
}
long long sum(long long *tree, int p) {
  long long ret = 0;
  while (p) {
    ret += tree[p];
    p -= p & -p;
  }
  return ret;
}

int main() {
  int t, n, i, max_el, *a;
  long long ans, *tree;

  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    a = new int[n];
    max_el = 0;
    for (i = 0; i < n; ++i) {
      scanf("%d", a + i);
      max_el = max(max_el, a[i]);
    }

    tree = new long long[max_el + 1]();
    ans = 0;
    for (i = n - 1; i >= 0; --i) {
      ans += sum(tree, a[i] - 1);
      add(tree, a[i], max_el, 1);
    }
    printf("%lld\n", ans);

    delete[] a;
    delete[] tree;
  }

  return 0;
}
