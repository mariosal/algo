#include <cstdio>

struct Piece {
  short x, y;
};
char **b;
short n, m;
Piece **p;

int queen(Piece *p, char k) {
  char dx[8] = {0, 1, 1, 1, 0, -1, -1, -1},
       dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
  int ret = k;

  for (char i = 0; i < k; ++i) {
    for (char j = 0; j < 8; ++j) {
      for (short k = 1; ; ++k) {
        if (p[i].x + k * dx[j] < 0 || p[i].x + k * dx[j] >= n ||
            p[i].y + k * dy[j] < 0 || p[i].y + k * dy[j] >= m) {
          break;
        }
        if (b[p[i].x + k * dx[j]][p[i].y + k * dy[j]] == 2) {
          break;
        }
        if (!b[p[i].x + k * dx[j]][p[i].y + k * dy[j]]) {
          ++ret;
          b[p[i].x + k * dx[j]][p[i].y + k * dy[j]] = 1;
        }
      }
    }
  }
  return ret;
}
int knight(Piece *p, char k) {
  char dx[8] = {1, 2, 2, 1, -1, -2, -2, -1},
       dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
  int ret = k;

  for (char i = 0; i < k; ++i) {
    for (char j = 0; j < 8; ++j) {
      if (p[i].x + dx[j] < 0 || p[i].x + dx[j] >= n ||
          p[i].y + dy[j] < 0 || p[i].y + dy[j] >= m) {
        continue;
      }
      if (b[p[i].x + dx[j]][p[i].y + dy[j]] == 2) {
        continue;
      }
      if (!b[p[i].x + dx[j]][p[i].y + dy[j]]) {
        ++ret;
        b[p[i].x + dx[j]][p[i].y + dy[j]] = 1;
      }
    }
  }
  return ret;
}
int pawn(Piece *p, char k) {
  return k;
}

int main() {
  char len[3];
  short i, j, k;
  int t, ans;

  for (t = 1; ; ++t) {
    scanf("%hd %hd", &n, &m);
    if (n == 0) {
      break;
    }

    b = new char*[n];
    for (i = 0; i < n; ++i) {
      b[i] = new char[m];
      for (j = 0; j < m; ++j) {
        b[i][j] = 0;
      }
    }

    ans = n * m;
    p = new Piece*[3];
    for (i = 0; i < 3; ++i) {
      scanf("%hd", &k);
      len[i] = k;
      p[i] = new Piece[k];
      for (j = 0; j < k; ++j) {
        scanf("%hd %hd", &p[i][j].x, &p[i][j].y);
        --p[i][j].x;
        --p[i][j].y;
        b[p[i][j].x][p[i][j].y] = 2;
      }
    }
    for (i = 0; i < 3; ++i) {
      switch (i) {
        case 0:
          ans -= queen(p[i], len[i]);
          break;
        case 1:
          ans -= knight(p[i], len[i]);
          break;
        case 2:
          ans -= pawn(p[i], len[i]);
          break;
      }
    }

    printf("Board %hd has %d safe squares.\n", t, ans);

    for (i = 0; i < n; ++i) {
      delete[] b[i];
    }
    delete[] b;
  }

  return 0;
}
