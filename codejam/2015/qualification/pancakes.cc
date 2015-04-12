#include <cstdio>
#include <climits>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int CanDo(int *diners, int count_diners, int special, int height) {
  vector<int> a(diners, diners + count_diners);

  int splits = 0;

  for (int i = 0; i < a.size(); ++i) {
    if (a[i] > height) {
      ++splits;
      if (splits > special) {
        return INT_MAX;
      }

      a.push_back(a[i] - height);
      a[i] = height;
    }
  }

  return splits + height;
}

int main(void) {
  int test_cases;
  scanf("%d", &test_cases);

  for (int i = 1; i <= test_cases; ++i) {
    int count_diners;
    scanf("%d", &count_diners);

    int max_pancakes = 0;
    int *diners = new int[count_diners];
    for (int j = 0; j < count_diners; ++j) {
      scanf("%d", &diners[j]);
      max_pancakes = max(max_pancakes, diners[j]);
    }

    int min_time = max_pancakes;
    for (int special = 1; special < max_pancakes; ++special) {
      int lo = 1;
      int hi = max_pancakes;
      while (lo < hi) {
        int mi = (lo + hi) / 2;
        if (CanDo(diners, count_diners, special, mi) != INT_MAX) {
          hi = mi;
        } else {
          lo = mi + 1;
        }
      }

      min_time = min(min_time, CanDo(diners, count_diners, special, lo));
    }

    printf("Case #%d: %d\n", i, min_time);
  }

  return 0;
}
