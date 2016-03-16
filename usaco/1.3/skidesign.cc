/*
  ID: mariosa1
  TASK: skidesign
  LANG: C++11
*/
#include <algorithm>
#include <climits>
#include <cstdio>

#ifdef _LP64
#define __PRIS_PREFIX "z"
#else
#define __PRIS_PREFIX
#endif

#define PRIuS __PRIS_PREFIX "u"

static int Cost(int* hills, size_t num_hills, int min_height) {
  int ret = 0;
  for (size_t i = 0; i < num_hills; ++i) {
    if (hills[i] < min_height) {
      ret += (min_height - hills[i]) * (min_height - hills[i]);
    } else if (min_height + 17 < hills[i]) {
      ret += (hills[i] - min_height - 17) * (hills[i] - min_height - 17);
    }
  }
  return ret;
}

int main() {
  freopen("skidesign.in", "r", stdin);
  freopen("skidesign.out", "w", stdout);

  size_t num_hills;
  scanf("%" PRIuS, &num_hills);

  int* hills = new int[num_hills];
  int min_height = INT_MAX;
  int max_height = INT_MIN;
  for (size_t i = 0; i < num_hills; ++i) {
    scanf("%d", hills + i);
    min_height = std::min(min_height, hills[i]);
    max_height = std::max(max_height, hills[i]);
  }

  int min_cost = INT_MAX;
  for (int i = min_height; i <= max_height - 17; ++i) {
    min_cost = std::min(min_cost, Cost(hills, num_hills, i));
  }

  printf("%d\n", min_cost);
  return 0;
}
