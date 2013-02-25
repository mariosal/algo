#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  char i, j;
  short a[3];

  scanf("%hd %hd %hd\n", &a[0], &a[1], &a[2]);
  sort(a, a + 3);
  for (i = 0; i < 3; ++i) {
    scanf("%c", &j);
    printf("%hd%s", a[j - 'A'], i == 2 ? "\n" : " ");
  }

  return 0;
}
