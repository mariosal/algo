/*
  ID: mariosa1
  TASK: palsquare
  LANG: C++11
*/
#include <cstdio>
#include <cstring>

static char* Reverse(char* str) {
  size_t size = strlen(str);
  char* ret = new char[size + 1];
  for (size_t i = 0; i < size; ++i) {
    ret[i] = str[size - 1 - i];
  }
  ret[size] = '\0';
  return ret;
}

static char* Convert(int num, int base) {
  char ret[10];
  size_t i = 0;
  for (; num > 0; num /= base, ++i) {
    char digit;
    if (num % base < 10) {
      digit = num % base + '0';
    } else {
      digit = num % base - 10 + 'A';
    }
    ret[i] = digit;
  }
  ret[i] = '\0';
  return Reverse(ret);
}

int main() {
  freopen("palsquare.in", "r", stdin);
  freopen("palsquare.out", "w", stdout);

  int base;
  scanf("%d", &base);

  for (int i = 1; i < 300; ++i) {
    char* square = Convert(i * i, base);
    char* reversed = Reverse(square);
    if (strcmp(square, reversed) == 0) {
      char* original = Convert(i, base);
      printf("%s %s\n", original, reversed);
      delete[] original;
    }
    delete[] square;
    delete[] reversed;
  }
  return 0;
}
