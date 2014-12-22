#include <cstdio>
#include <cmath>
#include <list>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
  short v;
  int w;
};
short n, **p, *T, *l;
int *d;
list<Edge> *E;

void dfs(short u) {
  short v;
  list<Edge>::iterator it;
  stack<short> s;

  d[u] = l[u] = 0;
  s.push(u);
  while (!s.empty()) {
    v = s.top();
    s.pop();
    for (it = E[v].begin(); it != E[v].end(); ++it) {
      l[it->v] = l[v] + 1;
      d[it->v] = d[v] + it->w;
      s.push(it->v);
    }
  }
}

void lca() {
  short i, j;
  for (i = 0; i < n; ++i) {
    p[i][0] = T[i];
    for (j = 1; 1 << j < n; ++j) {
      p[i][j] = -1;
    }
  }
  for (j = 1; 1 << j < n; ++j) {
    for (i = 0; i < n; ++i) {
      p[i][j] = j ? p[p[i][j - 1]][j - 1]: T[i];
    }
  }
}
int query(short u, short v) {
  short i, j, tmp;

  if (l[u] < l[v]) {
    tmp = u;
    u = v;
    v = tmp;
  }
  if (!l[u]) {
    return u;
  }

  for (j = 0; 1 << j <= l[u]; ++j);
  --j;
  for (i = j; i >= 0; --i) {
    if (l[u] - (1 << i) >= l[v]) {
      u = p[u][i];
    }
  }

  if (u == v) {
    return u;
  }
  for (i = j; i >= 0; --i) {
    if (p[u][i] != -1 && p[u][i] != p[v][i]) {
      u = p[u][i];
      v = p[v][i];
    }
  }
  return T[u];
}

int main() {
  char cmd[5];
  short u, v, t, tmp, i, j, k;
  int w;
  vector<bool> deg;

  scanf("%hd", &t);
  while (t--) {
    scanf("%hd", &n);
    T = new short[n];
    l = new short[n];
    p = new short*[n];
    d = new int[n];
    E = new list<Edge>[n];
    deg.resize(n);

    for (i = 0; i < n; ++i) {
      scanf("%hd %hd %d", &u, &v, &w);
      p[i] = new short[14]; // log_2(n)
      deg[v - 1] = true;
      T[v - 1] = u - 1;
      E[u - 1].push_back((Edge) {v - 1, w});
    }

    for (i = 0; i < n; ++i) {
      if (!deg[i]) {
        T[i] = i;
        dfs(i);
        break;
      }
    }
    lca();

    while (true) {
      scanf("%s", cmd);
      if (cmd[1] == 'I') {
        scanf("%hd %hd", &u, &v);
        --u;
        --v;
        printf("%d\n", d[u] + d[v] - 2 * d[query(u, v)]);
      }
      else if (cmd[1] == 'T') {
        scanf("%hd %hd %hd", &u, &v, &k);
        --u;
        --v;
        if (l[u] - l[query(u, v)] + 1 < k) {
          k = l[u] + l[v] - 2 * l[query(u, v)] + 2 - k;
          tmp = u;
          u = v;
          v = tmp;
        }

        tmp = u;
        for (j = 0; 1 << j <= l[u]; ++j);
        --j;
        for (i = j; i >= 0; --i) {
          if (p[u][i] != -1) {
            if (l[tmp] - l[p[u][i]] + 1 <= k) {
              u = p[u][i];
            }
          }
        }
        printf("%hd\n", u + 1);
      }
      else {
        break;
      }
    }

    delete[] l;
    delete[] T;
    delete[] p;
    delete[] d;
    delete[] E;
    deg.clear();
  }

  return 0;
}
