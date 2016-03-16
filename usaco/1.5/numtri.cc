/*
  ID: mariosa1
  TASK: numtri
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
  freopen("numtri.in", "r", stdin);
  freopen("numtri.out", "w", stdout);

  size_t num_rows;
  scanf("%" PRIuS, &num_rows);

  int** nums = new int*[num_rows];
  for (size_t i = 0; i < num_rows; ++i) {
    nums[i] = new int[i + 1];
    for (size_t j = 0; j < i + 1; ++j) {
      scanf("%d", nums[i] + j);
    }
  }

  int** sums = new int*[num_rows + 1];
  for (size_t i = 0; i <= num_rows; ++i) {
    sums[i] = new int[i + 2];
  }

  sums[0][0] = sums[0][1] = 0;
  for (size_t i = 1; i <= num_rows; ++i) {
    for (size_t j = 1; j <= i; ++j) {
      sums[i][j] = std::max(sums[i - 1][j - 1], sums[i - 1][j]);
      sums[i][j] += nums[i - 1][j - 1];
    }
  }

  int max_sum = 0;
  for (size_t i = 1; i <= num_rows; ++i) {
    max_sum = std::max(max_sum, sums[num_rows][i]);
  }

  printf("%d\n", max_sum);
  return 0;
}
