/*
  ID: mariosa1
  TASK: sort3
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
  freopen("sort3.in", "r", stdin);
  freopen("sort3.out", "w", stdout);

  size_t n;
  scanf("%" PRIuS, &n);

  int* nums = new int[n];
  int* sorted = new int[n];
  for (size_t i = 0; i < n; ++i) {
    scanf("%d", nums + i);
    sorted[i] = nums[i];
  }
  std::sort(sorted, sorted + n);

  int moves = 0;
  for (size_t i = 0; i < n; ++i) {
    if (nums[i] != sorted[i]) {
      for (size_t j = i + 1; j < n; ++j) {
        if (nums[i] == sorted[j] && nums[j] == sorted[i]) {
          int temp = nums[i];
          nums[i] = nums[j];
          nums[j] = temp;
          ++moves;
        }
      }
    }
  }

  for (size_t i = 0; i < n; ++i) {
    if (nums[i] != sorted[i] && nums[i] == 1) {
      moves += 2;
    }
  }

  printf("%d\n", moves);
  return 0;
}
