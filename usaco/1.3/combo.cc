/*
  ID: mariosa1
  TASK: combo
  LANG: C++11
*/
#include <cstdio>
#include <cstdlib>

static bool Valid(int range, int* correct, int* dial) {
  for (int i = 0; i < 3; ++i) {
    if (abs(dial[i] - correct[i]) > 2 &&
        abs(dial[i] - correct[i] - range) > 2 &&
        abs(dial[i] - correct[i] + range) > 2) {
      return false;
    }
  }
  return true;
}

int main() {
  freopen("combo.in", "r", stdin);
  freopen("combo.out", "w", stdout);

  int range, john[3], master[3];
  scanf("%d%d%d%d%d%d%d",
        &range,
        john, john + 1, john + 2,
        master, master + 1, master + 2);

  int solutions = 0;
  int dial[3];
  for (dial[0] = 1; dial[0] <= range; ++dial[0]) {
    for (dial[1] = 1; dial[1] <= range; ++dial[1]) {
      for (dial[2] = 1; dial[2] <= range; ++dial[2]) {
        if (Valid(range, john, dial) || Valid(range, master, dial)) {
          ++solutions;
        }
      }
    }
  }

  printf("%d\n", solutions);
  return 0;
}
