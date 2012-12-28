#include <cstdio>
#include <vector>

using namespace std;

char r, c, s[11] = "ALLIZZWELL", dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
     dy[8] = {0, 1, 1, 1, 0, -1, -1, -1}, **m;
vector<bool> *mark;

bool valid(char x, char y) {
  if (x < 0 || r <= x || y < 0 || c <= y) {
    return false;
  }
  return true;
}
bool dfs(char x, char y, char z) {
  if (z == 9) {
    return true;
  }
  mark[x][y] = true;
  for (int i = 0; i < 8; ++i) {
    if (valid(x + dx[i], y + dy[i])) {
      if (!mark[x + dx[i]][y + dy[i]] && m[x + dx[i]][y + dy[i]] == s[z + 1]) {
        if (dfs(x + dx[i], y + dy[i], z + 1)) {
          return true;
        }
      }
    }
  }
  mark[x][y] = false;
  return false;
}

int main() {
  bool found;
  char i, j;
  short t;

  scanf("%hd", &t);
  while (t--) {
    scanf("%hd %hd", &r, &c);

    m = new char*[r];
    mark = new vector<bool>[r];
    for (i = 0; i < r; ++i) {
      m[i] = new char[c + 1];
      scanf("%s", m[i]);
      mark[i].resize(c);
    }

    found = false;
    for (i = 0; i < r; ++i) {
      for (j = 0; j < c; ++j) {
        if (m[i][j] == 'A') {
          if (dfs(i, j, 0)) {
            found = true;
            i = r;
            j = c;
          }
        }
      }
    }
    printf("%s\n", found ? "YES" : "NO");

    for (i = 0; i < r; ++i) {
      delete[] m[i];
      mark[i].clear();
    }
    delete[] m;
    delete[] mark;
  }

  return 0;
}
