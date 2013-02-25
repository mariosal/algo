#include <cstdio>

int main() {
  short i, n;
  int ans;

  scanf("%hd", &n);
  ans = 0;
  for (i = 2; i < n - 1; ++i) {
    ans += (i - 1) * (n - i - 1);
  }
  printf("%d\n", ans * n / 4);

  return 0;
}
