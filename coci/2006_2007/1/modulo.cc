#include <cstdio>
#include <vector>

using namespace std;

int main() {
  char i, ans;
  short j;
  vector<bool> a(10);

  ans = 0;
  for (i = 0; i < 10; ++i) {
    scanf("%hd", &j);
    if (!a[j % 42]) {
      ++ans;
      a[j % 42] = true;
    }
  }
  printf("%d\n", ans);

  return 0;
}
