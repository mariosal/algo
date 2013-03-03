#include <cstdio>
#include <list>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

struct Edge {
  int v, w;
};
struct Node {
  int min, max;
};

void makeTree(list<Edge> *E, int *T, int *L, Node **rmq) {
  int u;
  stack<int> s;
  set<int> mark;
  list<Edge>::iterator it;

  T[0] = L[0] = 0;
  mark.insert(0);
  s.push(0);
  while (!s.empty()) {
    u = s.top();
    s.pop();

    for (it = E[u].begin(); it != E[u].end(); ++it) {
      if (mark.insert(it->v).second) {
        T[it->v] = u;
        L[it->v] = L[u] + 1;
        rmq[0][it->v] = (Node) {it->w, it->w};
        s.push(it->v);
      }
    }
  }
}

void init(int *T, int n, int **p, Node **rmq) {
  int i, j;

  for (i = 0; i < n; ++i) {
    p[0][i] = T[i];
    for (j = 1; 1 << j < n; ++j) {
      p[j][i] = -1;
    }
  }

  for (j = 1; 1 << j < n; ++j) {
    for (i = 0; i < n; ++i) {
      p[j][i] = p[j - 1][p[j - 1][i]];
      rmq[j][i] = (Node) {
        min(rmq[j - 1][i].min, rmq[j - 1][p[j - 1][i]].min),
        max(rmq[j - 1][i].max, rmq[j - 1][p[j - 1][i]].max),
      };
    }
  }
}

int lca(int *T, int *L, int **p, int u, int v) {
  int i, j;

  if (L[u] < L[v]) {
    swap(u, v);
  }
  if (!L[u]) {
    return u;
  }

  for (j = 0; 1 << j <= L[u]; ++j);
  --j;
  for (i = j; i >= 0; --i) {
    if (L[u] - (1 << i) >= L[v]) {
      u = p[i][u];
    }
  }
  if (u == v) {
    return u;
  }

  for (i = j; i >= 0; --i) {
    if (p[i][u] != -1 && p[i][u] != p[i][v]) {
      u = p[i][u];
      v = p[i][v];
    }
  }
  return T[u];
}

Node q(int *L, int **p, Node **rmq, int a, int u, int v) {
  int i, j, uu, vv ,ud, vd;
  Node ret = (Node) {1000000, 0};

  for (ud = 0; 1 << ud <= L[u]; ++ud);
  --ud;
  for (vd = 0; 1 << vd <= L[v]; ++vd);
  --vd;

  uu = u;
  vv = v;
  for (i = ud; i >= 0; --i) {
    if (L[uu] - (1 << i) >= L[a]) {
      ret.min = min(ret.min, rmq[i][uu].min);
      ret.max = max(ret.max, rmq[i][uu].max);
      uu = p[i][uu];
    }
  }
  for (i = vd; i >= 0; --i) {
    if (L[vv] - (1 << i) >= L[a]) {
      ret.min = min(ret.min, rmq[i][vv].min);
      ret.max = max(ret.max, rmq[i][vv].max);
      vv = p[i][vv];
    }
  }
  if (!L[u] && !L[v]) {
    return (Node) {0, 0};
  }
  return ret;
}

int main() {
  int a, i, j, n, m, u, v, w, *T, *L, **p;
  Node ans, **rmq;
  list<Edge> *E;

  scanf("%d", &n);

  for (j = 0; 1 << j <= n; ++j);

  T = new int[n];
  L = new int[n];
  p = new int*[j];
  rmq = new Node*[j];
  E = new list<Edge>[n];

  for (i = 0; i < j; ++i) {
    p[i] = new int[n];
    rmq[i] = new Node[n];
  }

  for (i = 0; i < n - 1; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    E[u - 1].push_back((Edge) {v - 1, w});
    E[v - 1].push_back((Edge) {u - 1, w});
  }
  makeTree(E, T, L, rmq);
  init(T, n, p, rmq);

  scanf("%d", &m);
  for (i = 0; i < m; ++i) {
    scanf("%d%d", &u, &v);
    a = lca(T, L, p, u - 1, v - 1);
    ans = q(L, p, rmq, a, u - 1, v - 1);
    printf("%d %d\n", ans.min, ans.max);
  }

  return 0;
}
