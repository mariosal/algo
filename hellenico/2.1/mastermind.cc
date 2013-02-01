#include <cstdio>

char *v, **pred;
short n, m, k;
int ans;

bool valid() {
  char i, j, l, correct, partly, *u;
  u = new char[k];
  for (i = 0; i < n; ++i) {
    for (j = 0; j < k; ++j) {
      u[j] = v[j];
    }

    correct = 0;
    partly = 0;
    for (j = 0; j < k; ++j) {
      if (pred[i][j] == u[j]) {
        ++correct;
      }
      else {
        for (l = 0; l < k; ++l) {
          if (pred[i][j] == u[l]) {
            if (pred[i][l] != u[l]) {
              u[l] = 0;
              ++partly;
              break;
            }
          }
        }
      }
    }
    if (correct != pred[i][k] || partly != pred[i][k + 1]) {
      return false;
    }
  }
  return true;
}

void dfs(short d) {
  char i;
  for (i = 1; i <= m; ++i) {
    v[d] = i;
    if (d < k - 1) {
      dfs(d + 1);
    }
    else if (valid()) {
      ++ans;
    }
  }
}

int main() {
  char i, j;
  short l;

  freopen("mastermind.in", "r", stdin);
  freopen("mastermind.out", "w", stdout);

  scanf("%hd %hd %hd", &n, &m, &k);
  v = new char[k];
  pred = new char*[n];
  for (i = 0; i < n; ++i) {
    pred[i] = new char[k + 3];
    for (j = 0; j < k + 2; ++j) {
      scanf("%hd", &l);
      pred[i][j] = l;
    }
    pred[i][k + 2] = '\0';
  }

  dfs(0);
  printf("%d\n", ans);

  return 0;
}
