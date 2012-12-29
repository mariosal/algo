#include <cstdio>

int main() {
  int t;
  long long i;

  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &i);
    printf("%lld\n", 192 + 250*(i - 1));
  }

  return 0;
}
