#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const short INF = 31000;
char b[2], e[2];
short n, m, **f;
vector<bool> *r;

short bfs() {
  char i, dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
  pair< short, pair<char, char> > p;
  set< pair<char, char> > s;
  queue< pair< short, pair<char, char> > > q;

  q.push(make_pair(0, make_pair(b[0], b[1])));
  while (!q.empty()) {
    p = q.front();
    q.pop();
    if (p.second.first < 0 || p.second.first >= n ||
        p.second.second < 0 || p.second.second >= m) {
      continue;
    }
    if (r[p.second.first][p.second.second] || p.first >= f[p.second.first][p.second.second]) {
      continue;
    }
    if (p.second.first == e[0] && p.second.second == e[1]) {
      return p.first;
    }
    if (!s.insert(p.second).second) {
      continue;
    }

    for (i = 0; i < 4; ++i) {
      q.push(make_pair(p.first + 1, make_pair(p.second.first + dx[i],
                                              p.second.second + dy[i])));
    }
  }
  return -1;
}

int main() {
  char i, j, c, dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
  short ans;
  pair<char, char> p;
  queue< pair<char, char> > q;

  scanf("%hd %hd", &n, &m);
  f = new short*[n];
  r = new vector<bool>[n];
  for (i = 0; i < n; ++i) {
    f[i] = new short[m];
    r[i].resize(m);
    for (j = 0; j < m; ++j) {
      r[i][j] = false;
      f[i][j] = INF;
    }
    scanf("\n");
    for (j = 0; j < m; ++j) {
      scanf("%c", &c);
      if (c == 'S') {
        b[0] = i;
        b[1] = j;
      }
      if (c == 'D') {
        e[0] = i;
        e[1] = j;
      }
      if (c == 'X') {
        r[i][j] = true;
      }
      if (c == '*') {
        f[i][j] = 0;
        q.push(make_pair(i, j));
      }
    }
  }

  while (!q.empty()) {
    p = q.front();
    q.pop();

    for (i = 0; i < 4; ++i) {
      if (p.first + dx[i] < 0 || p.first + dx[i] >= n ||
          p.second + dy[i] < 0 || p.second + dy[i] >= m) {
        continue;
      }
      if ((b[0] == p.first + dx[i] && b[1] == p.second + dy[i]) ||
          (e[0] == p.first + dx[i] && e[1] == p.second + dy[i]) ||
          r[p.first + dx[i]][p.second + dy[i]]) {
        continue;
      }
      if (f[p.first + dx[i]][p.second + dy[i]] > 1 + f[p.first][p.second]) {
        f[p.first + dx[i]][p.second + dy[i]] = 1 + f[p.first][p.second];
        q.push(make_pair(p.first + dx[i], p.second + dy[i]));
      }
    }
  }

  ans = bfs();
  if (ans == -1) {
    printf("KAKTUS\n");
  }
  else {
    printf("%hd\n", ans);
  }

  return 0;
}
