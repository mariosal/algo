#include <cstdio>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

short n;
char len_on, len_off, on[2], off[2];

bool valid(vector<bool> &v) {
  char i;
  for (i = 0; i < 2; ++i) {
    if ((i < len_on && !v[on[i]]) ||
        (i < len_off && v[off[i]])) {
      return false;
    }
  }
  return true;
}
void change(vector<bool> &v, char b) {
  char i;
  for (i = 0; i < n; ++i) {
    if ((b == 0) ||
        (b == 1 && i % 2 == 0) ||
        (b == 2 && i % 2 == 1)) {
      v[i] = !v[i];
    }
    else if (b == 3 && 3 * i < n) {
      v[3 * i] = !v[3 * i];
    }
  }
}

int main() {
  char a, b, c, d;
  short i;
  int m;
  vector<bool> v;
  set< vector<bool> > s;
  set< vector<bool> >::iterator it;

  freopen("lamps.in", "r", stdin);
  freopen("lamps.out", "w", stdout);

  scanf("%hd\n%d", &n, &m);
  v.resize(n);

  len_on = 0;
  while (1) {
    scanf("%hd", &i);
    if (i == -1) {
      break;
    }
    on[len_on++] = i - 1;
  }
  len_off = 0;
  while (1) {
    scanf("%hd", &i);
    if (i == -1) {
      break;
    }
    off[len_off++] = i - 1;
  }

  for (a = 0; a < 2; ++a) {
    for (b = 0; b < 2; ++b) {
      for (c = 0; c < 2; ++c) {
        for (d = 0; d < 2; ++d) {
          for (i = 0; i < n; ++i) {
            v[i] = 1;
          }
          if (a) change(v, 0);
          if (b) change(v, 1);
          if (c) change(v, 2);
          if (d) change(v, 3);

          if (a + b + c + d <= m && ((m - a - b - c - d) % 2 == 0) && valid(v)) {
            s.insert(v);
          }
        }
      }
    }
  }

  for (it = s.begin(); it != s.end(); ++it) {
    for (i = 0; i < it->size(); ++i) {
      printf("%c", (*it)[i] + '0');
    }
    printf("\n");
  }

  return 0;
}
