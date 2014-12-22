#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int i, j, k, n, m, ans, changes;
  map< pair<int, int>, int > a;
  map< pair<int, int>, int >::iterator l;

  freopen("nered.in", "r", stdin);
  freopen("nered.out", "w", stdout);

  scanf("%d %d", &n, &m);
  for (i = 0; i < m; ++i) {
    scanf("%d %d", &j, &k);
    ++a[make_pair(j, k)];
  }

  ans = m;
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= n; ++j) {
      for (k = 1; k <= m; ++k) {
        if (m % k || i + k - 1 > n || j + m / k - 1 > n) {
          continue;
        }

        changes = 0;
        for(l = a.begin(); l != a.end(); ++l) {
          changes += l->second;
          if (i <= l->first.first && l->first.first < i + k &&
              j <= l->first.second && l->first.second < j + m / k) {
            --changes;
          }
        }
        ans = min(ans, changes);
      }
    }
  }
  printf("%d\n", ans);

  return 0;
}
