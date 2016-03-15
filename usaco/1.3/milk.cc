/*
  ID: mariosa1
  TASK: milk
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

struct Farmer {
  bool operator<(const Farmer& farmer) const {
    if (cost == farmer.cost) {
      return units < farmer.units;
    }
    return cost < farmer.cost;
  }

  int cost;
  int units;
};

int main() {
  freopen("milk.in", "r", stdin);
  freopen("milk.out", "w", stdout);

  int required_amount;
  size_t num_farmers;
  scanf("%d%" PRIuS, &required_amount, &num_farmers);

  Farmer* farmers = new Farmer[num_farmers];
  for (size_t i = 0; i < num_farmers; ++i) {
    scanf("%d%d", &farmers[i].cost, &farmers[i].units);
  }
  std::sort(farmers, farmers + num_farmers);

  int current_amount = 0;
  int min_cost = 0;
  for (size_t i = 0; i < num_farmers; ++i) {
    if (required_amount == current_amount) {
      break;
    }
    if (required_amount >= current_amount + farmers[i].units) {
      min_cost += farmers[i].cost * farmers[i].units;
      current_amount += farmers[i].units;
    } else {
      min_cost += farmers[i].cost * (required_amount - current_amount);
      current_amount = required_amount;
    }
  }

  printf("%d\n", min_cost);
  return 0;
}
