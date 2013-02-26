#include <cstdio>
#include <algorithm>

using namespace std;

struct Edge {
  int u, v, w;
};
bool operator<(Edge a, Edge b) {
  return a.w < b.w;
}

struct Set {
  int p, r, n;
};
Set *s;
int find(int u) {
  if (u != s[u].p) {
    s[u].p = find(s[u].p);
  }
  return s[u].p;
}
void unite(int u, int v) {
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

long long kruskal(Edge *E, int n) {
  int u, v, i;
  long long ret;

  s = new Set[n];
  for (i = 0; i < n; ++i) {
    s[i] = (Set) {i, 0, 1};
  }

  sort(E, E + n - 1);
  ret = 0;
  for (i = 0; i < n - 1; ++i) {
    u = find(E[i].u);
    v = find(E[i].v);
    if (u != v) {
      ret += (long long)s[u].n * s[v].n * (E[i].w + 1) - 1;
      unite(u, v);
    }
  }

  return ret;
}

int main() {
  int i, n;
  Edge *E;

#ifdef CONTEST
  freopen("telecom.in", "r", stdin);
  freopen("telecom.out", "w", stdout);
#endif

  scanf("%d", &n);
  E = new Edge[n - 1];
  for (i = 0; i < n - 1; ++i) {
    scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].w);
    --E[i].u;
    --E[i].v;
  }
  printf("%lld\n", kruskal(E, n));

  return 0;
}
