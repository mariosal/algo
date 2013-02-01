#include <cstdio>
#include <cstring>
#include <bitset>
#include <algorithm>

using namespace std;

int main() {
  bitset<10> mark;
  char i, j, len_a,  a[9], *perm;
  int ans, b, c;

  freopen("digits.in", "r", stdin);
  freopen("digits.out", "w", stdout);

  scanf("%s", a);
  len_a = strlen(a);
  perm = new char[9 - len_a];
  for (i = 0; i < len_a; ++i) {
    mark[a[i] - '0'] = true;
  }

  for (i = 1, j = 0; i <= 9; ++i) {
    if (!mark[i]) {
      perm[j++] = i + '0';
    }
  }
  sort(perm, perm + 9 - len_a);

  ans = 0;
  while (next_permutation(perm, perm + 9 - len_a)) {
    for (i = 0; i < 8 - len_a; ++i) {
      b = 0;
      c = 0;
      for (j = 0; j <= i; ++j) {
        b *= 10;
        b += perm[j] - '0';
      }
      for (; j < 9 - len_a; ++j) {
        c *= 10;
        c += perm[j] - '0';
      }

      if (atoi(a) * b == c) {
        printf("%d %d\n", b, c);
        return 0;
      }
    }
  }
  printf("%d\n", ans);

  return 0;
}
