/*
  ID: mariosa1
  TASK: friday
  LANG: C++11
*/
#include <cstdio>
#include <map>

static bool Leap(int year) {
  return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

static int Days(int year, int month) {
  int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 1) {
    return days[month] + Leap(year);
  }
  return days[month];
}

int main() {
  freopen("friday.in", "r", stdin);
  freopen("friday.out", "w", stdout);

  int years;
  scanf("%d", &years);

  int frequency[7];  // frequency[0] is Saturday
  for (size_t i = 0; i < 7; ++i) {
    frequency[i] = 0;
  }

  int k = 0;
  for (int i = 1900; i < 1900 + years; ++i) {
    for (int j = 0; j < 12; ++j) {
      ++frequency[k];
      k = (k + Days(i, j) % 7) % 7;
    }
  }

  for (size_t i = 0; i < 7; ++i) {
    if (i > 0) {
      printf(" ");
    }
    printf("%d", frequency[i]);
  }
  printf("\n");
  return 0;
}
