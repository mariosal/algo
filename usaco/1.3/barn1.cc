/*
  ID: mariosa1
  TASK: barn1
  LANG: C++11
*/
#include <algorithm>
#include <cstdio>

#ifdef _LP64
#define __PRIS_PREFIX "z"
#else
#define __PRIS_PREFIX
#endif

#define PRIuS __PRIS_PREFIX "u"

int main() {
  freopen("barn1.in", "r", stdin);
  freopen("barn1.out", "w", stdout);

  size_t max_boards;
  size_t num_occupied;
  scanf("%" PRIuS "%*d%" PRIuS, &max_boards, &num_occupied);

  int* stalls = new int[num_occupied];
  for (size_t i = 0; i < num_occupied; ++i) {
    scanf("%d", stalls + i);
  }
  std::sort(stalls, stalls + num_occupied);

  int* gaps = new int[num_occupied - 1];
  for (size_t i = 0; i < num_occupied; ++i) {
    gaps[i] = stalls[i + 1] - stalls[i] - 1;
  }
  std::sort(gaps, gaps + num_occupied - 1, std::greater<int>());

  size_t length;
  if (num_occupied <= max_boards) {
    length = num_occupied;
  } else {
    length = stalls[num_occupied - 1] - stalls[0] + 1;
    for (size_t i = 0; i < max_boards - 1; ++i) {
      length -= gaps[i];
    }
  }

  printf("%" PRIuS "\n", length);
  return 0;
}
