#include <cstdio>
#include <algorithm>

using namespace std;

struct Edge {
  int s;
  int t;
  int w;
};

static bool operator<(const Edge& a, const Edge& b) {
  if (a.w == b.w) {
    if (a.s == b.s) {
      return a.t < b.t;
    }
    return a.s < b.s;
  }
  return a.w < b.w;
}

struct Set {
  int p;
  int r;
};

static Set* SetInit(int n) {
  Set* sets = new Set[n];
  for (int i = 0; i < n; ++i) {
    sets[i].p = i;
    sets[i].r = 0;
  }
  return sets;
}

static void SetReset(Set** sets) {
  delete[] *sets;
  *sets = NULL;
}

static int SetFind(Set* sets, int a) {
  if (sets[a].p != a) {
    sets[a].p = SetFind(sets, sets[a].p);
  }
  return sets[a].p;
}

static void SetUnite(Set* sets, int a, int b) {
  a = SetFind(sets, a);
  b = SetFind(sets, b);
  if (sets[a].r > sets[b].r) {
    sets[b].p = a;
  } else {
    sets[a].p = b;
    if (sets[a].r == sets[b].r) {
      ++sets[b].r;
    }
  }
}

static int Kruskal(Edge* edges, int n, int m) {
  sort(edges, edges + m);
  Set* sets = SetInit(n);
  int sum = 0;
  for (int i = 0; i < m; ++i) {
    if (SetFind(sets, edges[i].s) != SetFind(sets, edges[i].t)) {
      SetUnite(sets, edges[i].s, edges[i].t);
      sum += edges[i].w;
    }
  }
  SetReset(&sets);
  return sum;
}

int main() {
  freopen("uflights.in", "r", stdin);
  freopen("uflights.out", "w", stdout);

  int n, m;
  scanf("%d%d", &n, &m);

  Edge* edges = new Edge[m];
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &edges[i].s, &edges[i].t, &edges[i].w);
    --edges[i].s;
    --edges[i].t;
  }

  printf("%d\n", Kruskal(edges, n, m));
  delete[] edges;
  return 0;
}
