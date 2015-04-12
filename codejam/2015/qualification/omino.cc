#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
  bool a[4][4][4];

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 4; ++k) {
        a[i][j][k] = false;
      }
    }
  }

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      a[0][i][j] = true;
    }
  }

  int read = 1;
  for (int i = 1; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int k = j; k < 4; ++k) {
        if (i + 1 > (j + 1) * (k + 1) ||
            (((j + 1) * (k + 1)) % (i + 1)) == 1) {
          continue;
        }
        //printf("%d %d %d %d: ", read, i + 1, j + 1, k + 1);
        scanf("%d", &a[i][j][k]);
        ++read;
      }
    }
  }

  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; ++i) {
    int x, r, c;

    scanf("%d %d %d", &x, &r, &c);

    int temp = max(r, c);
    r = min(r, c);
    c = temp;

    if (a[x - 1][r - 1][c - 1]) {
      printf("Case #%d: GABRIEL\n", i);
    } else {
      printf("Case #%d: RICHARD\n", i);
    }
  }
  return 0;
}
