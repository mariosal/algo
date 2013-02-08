#include <cstdio>
#include <vector>

using namespace std;

short n;
vector<bool> *a, *mark;

void flood_fill(char i, char j) {
  if (i < 0 || n <= i || j < 0 || n <= j) {
    return;
  }
  if (!a[i][j] || mark[i][j]) {
    return;
  }

  mark[i][j] = true;
  flood_fill(i - 1, j);
  flood_fill(i, j + 1);
  flood_fill(i + 1, j);
  flood_fill(i, j - 1);
}

int main() {
  char i, j;
  short ans, k, m;

  freopen("karla.in", "r", stdin);
  freopen("karla.out", "w", stdout);

  scanf("%hd %hd", &n, &m);
  a = new vector<bool>[n];
  mark = new vector<bool>[n];

  for (i = 0; i < n; ++i) {
    a[i].reserve(n);
    mark[i].reserve(n);
    for (j = 0; j < n; ++j) {
      scanf("%hd", &k);
      a[i][j] = k > m;
    }
  }

  ans = 0;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      if (a[i][j] && !mark[i][j]) {
        flood_fill(i, j);
        ++ans;
      }
    }
  }
  printf("%d\n", ans);

  return 0;
}
