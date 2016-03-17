/*
  ID: mariosa1
  TASK: hamming
  LANG: C++11
*/
#include <cstdio>
#include <vector>

static int Distance(int a, int b) {
  int ret = 0;
  for (; a > 0; a >>= 1, b >>= 1) {
    if (a % 2 != b % 2) {
      ++ret;
    }
  }
  return ret;
}

int main() {
  freopen("hamming.in", "r", stdin);
  freopen("hamming.out", "w", stdout);

  int n, b, d;
  scanf("%d%d%d", &n, &b, &d);

  int end = 1;
  for (int i = 0; i < b; ++i) {
    end <<= 1;
  }

  std::vector<int> codewords;
  for (int i = 0; i < end; ++i) {
    bool valid = true;
    for (int j = 0; j < codewords.size(); ++j) {
      if (Distance(i, codewords[j]) < d) {
        valid = false;
        break;
      }
    }
    if (valid) {
      codewords.push_back(i);
    }
    if (codewords.size() == n) {
      break;
    }
  }

  for (int i = 0; i < codewords.size(); ++i) {
    if (i % 10 == 0 && i != 0) {
      printf("\n");
    }
    printf("%d", codewords[i]);
    if (i % 10 != 9 && i != codewords.size() - 1) {
      printf(" ");
    }
  }
  printf("\n");
  return 0;
}
