#include <cstdio>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

struct Edge {
  int trg, depth;
};

int dfs(list<int> *E, int src) {
  int max_depth;
  Edge e;
  stack< Edge > s;
  list<int>::iterator i;

  max_depth = 0;
  s.push((Edge) {src, 1});
  while (!s.empty()) {
    e = s.top();
    s.pop();

    max_depth = max(max_depth, e.depth);
    for (i = E[e.trg].begin(); i != E[e.trg].end(); ++i) {
      s.push((Edge) {*i, e.depth + 1});
    }
  }
  return max_depth;
}

int main() {
  int i, m, max_depth, n, u, v;
  vector<bool> in;
  list<int> *E; // Contains the edges of the graph

  //freopen("scidinner.in", "r", stdin);
  //freopen("scidinner.out", "w", stdout);

  scanf("%d %d", &n, &m);
  E = new list<int>[n];
  in.reserve(n);

  while (m--) {
    scanf("%d %d", &u, &v);
    if (u != v) { // No edges from a vertex to itself save comparisons in dfs
      E[u - 1].push_back(v - 1);
      in[v - 1] = true; // If there is an edge (u, v), then v is not a root
    }
  }

  max_depth = 0;
  for (i = 0; i < n; ++i) {
    if (!in[i]) { // Starting from roots guarantees visiting all the vertices
      max_depth = max(max_depth, dfs(E, i));
    }
  }
  printf("%d\n", max_depth);

  return 0;
}
