#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

struct Block {
  int x, y, z;
};
Block make_b(int i, int j, int k) {
  int a[3] = {i, j, k};
  sort(a, a + 3);
  return (Block) {a[0], a[1], a[2]};
}

struct Area {
  int x, y;
};
bool operator<(Area a, Area b) {
  if (a.x == b.x) {
    return a.y < b.y;
  }
  return a.x < b.x;
}
Area make_a(int i, int j) {
  return (Area) {min(i, j), max(i, j)};
}

short n;
Block *b;
map<Area, int> w;
void memo(Area a) {
  if (w.find(a) != w.end()) {
    return;
  }

  w[a] = 0;
  for (char i = 0; i < n; ++i) {
    if (b[i].x < a.x && b[i].y < a.y) {
      memo(make_a(b[i].x, b[i].y));
      w[a] = max(w[a], b[i].z + w[make_a(b[i].x, b[i].y)]);
    }
    if (b[i].x < a.x && b[i].z < a.y) {
      memo(make_a(b[i].x, b[i].z));
      w[a] = max(w[a], b[i].y + w[make_a(b[i].x, b[i].z)]);
    }
    if (b[i].y < a.x && b[i].z < a.y) {
      memo(make_a(b[i].y, b[i].z));
      w[a] = max(w[a], b[i].x + w[make_a(b[i].y, b[i].z)]);
    }
  }
}

int main() {
  short i;
  int max_s;

  while (true) {
    scanf("%hd", &n);
    if (!n) {
      break;
    }

    b = new Block[n];

    max_s = 0;
    for (i = 0; i < n; ++i) {
      scanf("%d %d %d", &b[i].x, &b[i].y, &b[i].z);
      b[i] = make_b(b[i].x, b[i].y, b[i].z);
      max_s = max(max_s, b[i].z);
    }
    memo(make_a(max_s + 1, max_s + 1));
    printf("%d\n", w[make_a(max_s + 1, max_s + 1)]);

    delete[] b;
    w.clear();
  }

  return 0;
}
