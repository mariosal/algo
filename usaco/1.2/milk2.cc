/*
  ID: mariosa1
  TASK: milk2
  LANG: C++11
*/
#include <cstdio>
#include <algorithm>

#ifdef _LP64
#define __PRIS_PREFIX "z"
#else
#define __PRIS_PREFIX
#endif

#define PRIuS __PRIS_PREFIX "u"

struct Interval {
  bool operator<(const Interval& interval) const {
    if (begin == interval.begin) {
      return end < interval.end;
    }
    return begin < interval.begin;
  }

  int begin;
  int end;
};

int main() {
  freopen("milk2.in", "r", stdin);
  freopen("milk2.out", "w", stdout);

  size_t num_intervals;
  scanf("%" PRIuS, &num_intervals);

  Interval* intervals = new Interval[num_intervals];
  for (size_t i = 0; i < num_intervals; ++i) {
    scanf("%d%d", &intervals[i].begin, &intervals[i].end);
  }

  std::sort(intervals, intervals + num_intervals);
  int work = 0;
  int idle = 0;
  int current_begin = intervals[0].begin;
  int current_end = intervals[0].end;
  for (size_t i = 0; i < num_intervals; ++i) {
    if (intervals[i].begin <= current_end) {
      current_end = std::max(current_end, intervals[i].end);
    } else {
      idle = std::max(idle, intervals[i].begin - current_end);
      current_begin = intervals[i].begin;
      current_end = intervals[i].end;
    }

    work = std::max(work, current_end - current_begin);
  }
  printf("%d %d\n", work, idle);
  return 0;
}
