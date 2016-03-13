/*
  ID: mariosa1
  TASK: gift1
  LANG: C++11
*/
#include <cstdio>
#include <cstring>
#include <map>

#ifdef _LP64
#define __PRIS_PREFIX "z"
#else
#define __PRIS_PREFIX
#endif

#define PRIuS __PRIS_PREFIX "u"

static bool compare(const char*a, const char* b) {
  return strcmp(a, b) < 0;
}

int main() {
  freopen("gift1.in", "r", stdin);
  freopen("gift1.out", "w", stdout);

  size_t num_people;
  scanf("%" PRIuS, &num_people);

  char** people = new char*[num_people];
  std::map<const char*, int, bool (*)(const char*, const char*)> money(compare);
  for (size_t i = 0; i < num_people; ++i) {
    people[i] = new char[15];
    scanf("%s", people[i]);
    money[people[i]] = 0;
  }

  for (size_t i = 0; i < num_people; ++i) {
    char giver[15];
    int amount;
    size_t num_receivers;
    scanf("%s%d%" PRIuS, giver, &amount, &num_receivers);
    if (amount == 0 || num_receivers == 0) {
      continue;
    }

    money[giver] -= amount / num_receivers * num_receivers;
    for (size_t j = 0; j < num_receivers; ++j) {
      char receiver[15];
      scanf("%s", receiver);
      money[receiver] += amount / num_receivers;
    }
  }

  for (size_t i = 0; i < num_people; ++i) {
    printf("%s %d\n", people[i], money[people[i]]);
  }

  return 0;
}
