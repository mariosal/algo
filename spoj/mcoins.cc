#include <cstdio>
#include <bitset>
#include <vector>

using namespace std;

int main() {
  const int N = 1000001;
  bool p;
  char k, l;
  short m;
  int i, j, n;
  bitset<N + 1> w;

#ifdef CONTEST
  freopen("coins.in", "r", stdin);
  freopen("coins.out", "w", stdout);
#endif

  scanf("%c %c %hd", &k, &l, &m);
  k -= '0';
  l -= '0';

  for (i = 1; i <= N; ++i) {
    if (!w[i - 1]) {
      w[i] = true;
    } else if (i >= l && !w[i - l]) {
      w[i] = true;
    } else if (i >= k && !w[i - k]) {
      w[i] = true;
    }
  }

  for (i = 0; i < m; ++i) {
    scanf("%d", &n);
    printf("%c", w[n] ? 'A' : 'B');
  }
  printf("\n");

  return 0;
}
