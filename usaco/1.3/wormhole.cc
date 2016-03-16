/*
  ID: mariosa1
  TASK: wormhole
  LANG: C++11
*/
#include <cstdio>

#ifdef _LP64
#define __PRIS_PREFIX "z"
#else
#define __PRIS_PREFIX
#endif

#define PRIuS __PRIS_PREFIX "u"

struct Point {
  int x;
  int y;
};

static bool Check(size_t num_holes, const size_t* next, const size_t* pairs) {
  for (size_t i = 1; i <= num_holes; ++i) {
    size_t pos = i;
    for (size_t j = 1; j <= num_holes; ++j) {
      pos = next[pairs[pos]];
    }
    if (pos != 0) {
      return true;
    }
  }
  return false;
}

static int NumCycles(size_t num_holes, const size_t* next) {
  static size_t* pairs = new size_t[num_holes + 1]();
  size_t i;
  for (i = 1; i <= num_holes; ++i) {
    if (pairs[i] == 0) {
      break;
    }
  }

  if (i > num_holes) {
    return Check(num_holes, next, pairs);
  }

  int ret = 0;
  for (size_t j = i + 1; j <= num_holes; ++j) {
    if (pairs[j] == 0) {
      pairs[i] = j;
      pairs[j] = i;
      ret += NumCycles(num_holes, next);
      pairs[i] = 0;
      pairs[j] = 0;
    }
  }

  return ret;
}

int main() {
  freopen("wormhole.in", "r", stdin);
  freopen("wormhole.out", "w", stdout);

  size_t num_holes;
  scanf("%" PRIuS, &num_holes);

  Point* holes = new Point[num_holes + 1];
  for (size_t i = 1; i <= num_holes; ++i) {
    scanf("%d%d", &holes[i].x, &holes[i].y);
  }

  size_t* next = new size_t[num_holes + 1]();
  for (size_t i = 1; i <= num_holes; ++i) {
    for (size_t j = 1; j <= num_holes; ++j) {
      if (holes[i].y == holes[j].y && holes[i].x < holes[j].x) {
        if (next[i] == 0 || holes[j].x < holes[next[i]].x) {
          next[i] = j;
        }
      }
    }
  }

  printf("%d\n", NumCycles(num_holes, next));
  return 0;
}
