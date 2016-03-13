/*
  ID: mariosa1
  TASK: namenum
  LANG: C++11
*/
#include <cstdio>
#include <cinttypes>
#include <map>

static int64_t Hash(const std::map<char, int>& map, const char* str) {
  int64_t ret = 0;
  for (size_t i = 0; str[i] != '\0'; ++i) {
    ret = 10 * ret + map.at(str[i]);
  }
  return ret;
}

int main() {
  freopen("namenum.in", "r", stdin);
  freopen("namenum.out", "w", stdout);

  int64_t num;
  scanf("%" PRId64, &num);

  FILE* dictionary = fopen("dict.txt", "r");

  std::map<char, int> map;
  map['A'] = map['B'] = map['C'] = 2;
  map['D'] = map['E'] = map['F'] = 3;
  map['G'] = map['H'] = map['I'] = 4;
  map['J'] = map['K'] = map['L'] = 5;
  map['M'] = map['N'] = map['O'] = 6;
  map['P'] = map['R'] = map['S'] = 7;
  map['T'] = map['U'] = map['V'] = 8;
  map['W'] = map['X'] = map['Y'] = 9;
  map['Q'] = map['Z'] = 0;

  bool printed = false;
  while (true) {
    char name[13];
    if (fscanf(dictionary, "%s", name) == EOF) {
      break;
    }

    if (num == Hash(map, name)) {
      printf("%s\n", name);
      printed = true;
    }
  }
  if (!printed) {
    printf("NONE\n");
  }

  return 0;
}
