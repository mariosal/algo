/*
  ID: mariosa1
  TASK: ride
  LANG: C++11
*/
#include <cstdio>

static int Mod(char* str) {
  int ret = 1;
  for (size_t i = 0; str[i] != '\0'; ++i) {
    char num = str[i] - 'A' + 1;
    ret = (ret * (num % 47)) % 47;
  }
  return ret;
}

int main() {
  freopen("ride.in", "r", stdin);
  freopen("ride.out", "w", stdout);

  char comet[7], group[7];
  scanf("%s%s", comet, group);
  if (Mod(comet) == Mod(group)) {
    printf("GO\n");
  } else {
    printf("STAY\n");
  }
  return 0;
}
