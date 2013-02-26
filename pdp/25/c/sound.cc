#include <cstdio>
#include <set>

using namespace std;

int main() {
  short m;
  int i, j, n, c, *a;
  multiset<int> s;

#ifdef CONTEST
  freopen("sound.in", "r", stdin);
  freopen("sound.out", "w", stdout);
#endif

  scanf("%d %hd %d", &n, &m, &c);
  a = new int[n];
  for (i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }

  j = 0;
  s.insert(a, a + m);
  for (i = 0; i + m - 1 < n; ++i) {
    if (i) {
      s.erase(a[i - 1]);
      s.insert(a[i + m - 1]);
    }
    if (*s.end() - *s.begin() <= c) {
      printf("%d\n", i + 1);
      ++j;
    }
  }
  if (j == 0) {
    printf("NULL\n");
  }

  return 0;
}
