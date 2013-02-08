#include <cstdio>
#include <set>
#include <queue>

using namespace std;

int dp(char **m, short n) {
  const long long MOD = (2LL << 30LL) - 1;
  short i, j;
  int **w;

  w = new int*[n];
  for (i = 0; i < n; ++i) {
    w[i] = new int[n]();
  }

  w[0][0] = 1;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      if (i + 1 < n) {
        if (m[i + 1][j] == '.') {
          w[i + 1][j] = ((long long)w[i + 1][j] + (long long)w[i][j]) % MOD;
        }
      }
      if (j + 1 < n) {
        if (m[i][j + 1] == '.') {
          w[i][j + 1] = ((long long)w[i][j + 1] + (long long)w[i][j]) % MOD;
        }
      }
    }
  }
  return w[n - 1][n - 1];
}
bool dfs(char **m, char *dx, char *dy, short n) {
  char i;
  pair<short, short> p;
  set< pair<short, short> > mark;
  queue< pair<short, short> > q;

  q.push(make_pair(0, 0));
  while (!q.empty()) {
    p = q.front();
    q.pop();
    if (p.first < 0 || n <= p.first ||
        p.second < 0 || n <= p.second ||
        m[p.first][p.second] == '#') {
      continue;
    }
    if (!mark.insert(p).second) {
      continue;
    }
    if (p.first == n - 1 && p.second == n - 1) {
      return true;
    }

    for (i = 0; i < 4; ++i) {
      q.push(make_pair(p.first + dx[i], p.second + dy[i]));
    }
  }
  return false;
}

int main() {
  char **m, dx[4] = {0, 1, 0, -1},
            dy[4] = {-1, 0, 1, 0};
  short n, i;
  int ans;

  scanf("%hd", &n);
  m = new char*[n];
  for (i = 0; i < n; ++i) {
    m[i] = new char[n + 1];
    scanf("%s", m[i]);
  }

  ans = dp(m, n);
  if (ans) {
    printf("%d\n", ans);
  }
  else {
    if (dfs(m, dx, dy, n)) {
      printf("THE GAME IS A LIE\n");
    }
    else {
      printf("INCONCEIVABLE\n");
    }
  }

  return 0;
}
