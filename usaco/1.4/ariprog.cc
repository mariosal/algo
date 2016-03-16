/*
  ID: mariosa1
  TASK: ariprog
  LANG: C++11
*/
#include <cstdio>

int main() {
  freopen("ariprog.in", "r", stdin);
  freopen("ariprog.out", "w", stdout);

  int length;
  int limit;
  scanf("%d%d", &length, &limit);

  bool* marked = new bool[2 * limit * limit + 1]();
  for (int i = 0; i <= limit; ++i) {
    for (int j = i; j <= limit; ++j) {
      marked[i * i + j * j] = true;
    }
  }

  bool none = true;
  for (int j = 1; (length - 1) * j <= 2 * limit * limit; ++j) {
    for (int i = 0; i + (length - 1) * j <= 2 * limit * limit; ++i) {
      if (!marked[i]) {
        continue;
      }

      bool valid = true;
      for (int k = 1; k < length; ++k) {
        if (!marked[i + k * j]) {
          valid = false;
          break;
        }
      }

      if (valid) {
        none = false;
        printf("%d %d\n", i, j);
      }
    }
  }

  if (none) {
    printf("NONE\n");
  }
  return 0;
}
