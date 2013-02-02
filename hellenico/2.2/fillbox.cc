#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

struct Dim {
  int l, w, h;
};
bool operator<(Dim a, Dim b) {
  if (a.l == b.l) {
    if (a.w == b.w) {
      return a.h < b.h;
    }
    return a.w < b.w;
  }
  return a.l < b.l;
}
Dim make_dim(int l, int w, int h) {
  int a[3] = {l, w, h};
  sort(a, a + 3);
  return (Dim) {a[0], a[1], a[2]};
}

map<Dim, long long> w;
void memo(Dim d) {
  char i;
  int box;
  Dim a, b, c;

  if (d.l == 0) {
    w[d] = 0;
  }
  if (w.find(d) != w.end()) {
    return;
  }

  for (i = 19; i >= -1; --i) {
    box = i == -1 ? 1 : 2 << i;
    if (box > d.l || box > d.w || box > d.h) {
      continue;
    }

    a = make_dim(d.l - box, box, box);
    b = make_dim(d.l, d.w - box, box);
    c = make_dim(d.l, d.w, d.h - box);
    memo(a);
    memo(b);
    memo(c);
    w[d] = 1 + w[a] + + w[b] + w[c];
    break;
  }
}

int main() {
  int l, wi, h;
  Dim d;

#ifdef CONTEST
  freopen("fillbox.in", "r", stdin);
  freopen("fillbox.out", "w", stdout);
#endif

  scanf("%d %d %d", &l, &wi, &h);
  memo(make_dim(l, wi, h));
  printf("%lld\n", w[make_dim(l, wi, h)]);

  return 0;
}
