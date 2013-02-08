#include <iostream>
#include <map>
#include <string>

using namespace std;

void add(int *tree, int p, int n, int v) {
  while (p <= n) {
    tree[p] += v;
    p += p & -p;
  }
}
int sum(int *tree, int p) {
  int ret = 0;
  while (p) {
    ret += tree[p];
    p -= p & -p;
  }
  return ret;
}

int main() {
  int t, n, i, ans, *a, *tree;
  string s;
  map<string, short> m;

  cin >> t;
  while (t--) {
    cin >> n;
    a = new int[n];
    tree = new int[n + 1]();

    for (i = 1; i <= n; ++i) {
      cin >> s;
      m[s] = i;
    }
    for (i = 0; i < n; ++i) {
      cin >> s;
      a[i] = m[s];
    }

    ans = 0;
    for (i = n - 1; i >= 0; --i) {
      ans += sum(tree, a[i] - 1);
      add(tree, a[i], n, 1);
    }
    cout << ans << '\n';

    delete[] a;
    delete[] tree;
    m.clear();
  }

  return 0;
}
