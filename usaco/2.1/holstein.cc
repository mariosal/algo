/*
  ID: mariosa1
  TASK: holstein
  LANG: C++11
*/
#include <cstdio>
#include <set>

#ifdef _LP64
#define __PRIS_PREFIX "z"
#else
#define __PRIS_PREFIX
#endif

#define PRIuS __PRIS_PREFIX "u"

int main() {
  freopen("holstein.in", "r", stdin);
  freopen("holstein.out", "w", stdout);

  size_t num_vitamins;
  scanf("%" PRIuS, &num_vitamins);

  int* vitamins = new int[num_vitamins];
  for (size_t i = 0; i < num_vitamins; ++i) {
    scanf("%d", vitamins + i);
  }

  size_t num_feeds;
  scanf("%" PRIuS, &num_feeds);

  int** feeds = new int*[num_feeds];
  for (size_t i = 0; i < num_feeds; ++i) {
    feeds[i] = new int[num_vitamins];
    for (size_t j = 0; j < num_vitamins; ++j) {
      scanf("%d", feeds[i] + j);
    }
  }

  int end = 1;
  for (size_t i = 0; i < num_feeds; ++i) {
    end <<= 1;
  }

  int* sums = new int[num_vitamins];
  std::set<size_t> cur_sol;
  std::set<size_t> opt_sol;
  for (int i = 0; i < end; ++i) {
    for (size_t j = 0; j < num_vitamins; ++j) {
      sums[j] = 0;
    }

    int mask = i;
    for (size_t j = 0; j < num_feeds; ++j) {
      if ((mask & 1) == 1) {
        cur_sol.insert(j + 1);
        for (size_t k = 0; k < num_vitamins; ++k) {
          sums[k] += feeds[j][k];
        }
      }
      mask >>= 1;
    }

    bool valid = true;
    for (size_t j = 0; j < num_vitamins; ++j) {
      if (sums[j] < vitamins[j]) {
        valid = false;
        break;
      }
    }

    if (valid) {
      if (opt_sol.empty() || opt_sol.size() > cur_sol.size()) {
        opt_sol = cur_sol;
      }
    }

    cur_sol.clear();
  }

  printf("%" PRIuS, opt_sol.size());
  for (auto it = opt_sol.begin(); it != opt_sol.end(); ++it) {
    printf(" %" PRIuS, *it);
  }
  printf("\n");
  return 0;
}
