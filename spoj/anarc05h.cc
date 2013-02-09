#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

char n, a[26];
map<pair<char, char>, int> w;
void memo(pair<char, char> p) {
  if (p.first >= n) {
    w[p] = 1;
    return;
  }
  if (w.find(p) != w.end()) {
    return;
  }

  char sum = 0;
  w[p] = 0;
  for (char i = p.first; i < n; ++i) {
    sum += a[i] - '0';
    if (sum >= p.second) {
      memo(make_pair(i + 1, sum));
      w[p] += w[make_pair(i + 1, sum)];
    }
  }
}

int main() {
  for (int i = 1; ; ++i) {
    scanf("%s", a);
    if (a[0] == 'b') {
      break;
    }

    n = strlen(a);
    memo(make_pair(0, 0));
    printf("%d. %d\n", i, w[make_pair(0, 0)]);

    w.clear();
  }

  return 0;
}
