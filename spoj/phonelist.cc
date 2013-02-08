#include <cstdio>
#include <map>

using namespace std;

struct Trie {
  bool is_word;
  int child[11];
};

bool add(Trie *T, int &size, char *s) {
  char i;
  int cur, j;

  cur = 0;
  for (i = 0; s[i]; ++i) {
    j = T[cur].child[s[i] - '0'];
    if (!j) {
      ++size;
      T[cur].child[s[i] - '0'] = size;
      j = size;
    } else if (T[j].is_word) {
      return false;
    }
    cur = j;
  }
  T[cur].is_word = true;
  for (i = 0; i < 10; ++i) {
    if (T[cur].child[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  bool br;
  char s[11];
  short t, n;
  int size;
  Trie *T;

  scanf("%hd", &t);
  while (t--) {
    size = 0;
    T = new Trie[100000];
    br = false;
    scanf("%hd", &n);
    while (n--) {
      scanf("%s", s);
      if (!br) {
        if (!add(T, size, s)) {
          br = true;
        }
      }
    }
    if (br) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
    delete[] T;
  }

  return 0;
}
