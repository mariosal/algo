#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  short t, n, wi, he, i, j, k;
  int **w;

  scanf("%hd", &t);
  while (t--) {
    scanf("%hd%hd%hd", &wi, &he, &n);
    w = new int*[wi + 1];
    for (i = 0; i <= wi; ++i) {
      w[i] = new int[he + 1];
      for (j = 0; j <= he; ++j) {
        w[i][j] = i * j;
      }
    }

    for (i = 0; i < n; ++i) {
      scanf("%hd%hd", &j, &k);
      w[j][k] = 0;
    }

    for (i = 0; i <= wi; ++i) {
      for (j = 0; j <= he; ++j) {
        for (k = 0; k <= i; ++k) {
          w[i][j] = min(w[i][j], w[k][j] + w[i - k][j]);
        }
        for (k = 0; k <= j; ++k) {
          w[i][j] = min(w[i][j], w[i][k] + w[i][j - k]);
        }
      }
    }
    printf("%d\n", w[wi][he]);

    for (i = 0; i <= wi; ++i) {
      delete[] w[i];
    }
    delete[] w;
  }

  return 0;
}
