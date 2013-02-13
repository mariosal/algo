#include <cstdio>
#include <algorithm>

using namespace std;

struct Edge {
  short u, v, w;
};
bool operator<(Edge a, Edge b) {
  if (a.w == b.w) {
    if (a.u == b.u) {
      return a.v < b.v;
    }
    return a.u < b.u;
  }
  return a.w < b.w;
}

struct Set {
  short p, r, n;
};
Set *s;
short find(short u) {
  if (u != s[u].p) {
    s[u].p = find(s[u].p);
  }
  return s[u].p;
}
void unite(short u, short v) {
  u = find(u);
  v = find(v);
  if (s[u].r > s[v].r) {
    s[v].p = u;
    s[u].n += s[v].n;
  }
  else {
    s[u].p = v;
    s[v].n += s[u].n;
    if (s[u].r == s[v].r) {
      ++s[v].r;
    }
  }
}
long long kruskal(Edge *E, short n, short m) {
  short i, u, v;
  long long ret;

  s = new Set[n];
  for (i = 0; i < n; ++i) {
    s[i] = (Set) {i, 0, 1};
  }

  ret = 0;
  sort(E, E + m);
  for (i = 0; i < m; ++i) {
    u = find(E[i].u);
    v = find(E[i].v);
    if (u != v) {
      ret += (long long)s[u].n * s[v].n * (E[i].w + 1) - 1;
      unite(u, v);
    }
  }
  delete[] s;

  return ret;
}

int main() {
  short i, n, u, v, w;
  int t;
  Edge *E;

  scanf("%d", &t);
  while (t--) {
    scanf("%hd", &n);
    E = new Edge[n - 1];

    for (i = 0; i < n - 1; ++i) {
      scanf("%hd %hd %hd", &u, &v, &w);
      E[i] = (Edge) {u - 1, v - 1, w};
    }

    printf("%lld\n", kruskal(E, n, n - 1));
    delete[] E;
  }

  return 0;
}
