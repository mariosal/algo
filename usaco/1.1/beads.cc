/*
  ID: mariosa1
  TASK: beads
  LANG: C++11
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

#ifdef _LP64
#define __PRIS_PREFIX "z"
#else
#define __PRIS_PREFIX
#endif

#define PRIuS __PRIS_PREFIX "u"

int main() {
  freopen("beads.in", "r", stdin);
  freopen("beads.out", "w", stdout);

  size_t num_beads;
  scanf("%" PRIuS, &num_beads);

  char* beads = new char[num_beads + 1];
  scanf("%s", beads);

  char* cat = new char[2 * num_beads + 1];
  strcpy(cat, beads);
  strcat(cat, beads);

  size_t max_beads = 0;
  for (size_t i = 0; i < num_beads; ++i) {
    size_t current_beads = 0;
    size_t pivot = i;
    for (int j = cat[i] != 'w'; j < 3; ++j) {
      char color = cat[pivot];
      while (pivot < num_beads + i && (cat[pivot] == color ||
                                       cat[pivot] == 'w')) {
        ++current_beads;
        ++pivot;
      }
    }

    max_beads = std::max(max_beads, current_beads);
  }
  printf("%" PRIuS "\n", max_beads);
  return 0;
}
