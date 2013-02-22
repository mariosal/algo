#include <cstdio>
#include <cstring>

int main() {
  char i, n, dec, **a, s[16];

  scanf("%s", s);
  n = strlen(s);
  a = new char*[5];
  for (i = 0; i < 5; ++i) {
    a[i] = new char[5 * n + 1544234];
  }

  for (i = 0; i < n; ++i) {
    dec = i % 3 == 2 ? '*' : '#';
    sprintf(a[0] + 4 * i, "..%c..", dec);
    sprintf(a[1] + 4 * i, ".%c.%c.", dec);
    sprintf(a[2] + 4 * i, "%c.%c.%c",
            (i % 3 == 2 || (i - 1) % 3 == 2) ? '*' : '#', s[i], dec);
    sprintf(a[3] + 4 * i, ".%c.%c.", dec);
    sprintf(a[4] + 4 * i, "..%c..", dec);
  }

  for (i = 0; i < 5; ++i) {
    printf("%s\n", a[i]);
  }

  return 0;
}
