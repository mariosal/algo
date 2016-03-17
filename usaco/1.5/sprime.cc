/*
  ID: mariosa1
  TASK: sprime
  LANG: C++11
*/
#include <cstdio>
#include <map>
#include <set>

static bool Prime(std::map<int, bool>& marked, int num) {
  if (marked.find(num) != marked.end()) {
    return marked[num];
  }
  if (num == 2) {
    marked[num] = true;
    return true;
  }
  if (num <= 1 || (num & 1) == 0) {
    marked[num] = false;
    return false;
  }
  for (int i = 3; i * i <= num; i += 2) {
    if (num % i == 0) {
      marked[num] = false;
      return false;
    }
  }
  marked[num] = true;
  return true;
}

static void Check(std::set<int>& primes, std::map<int, bool>& marked, int* ten,
                  int length, int num) {
  bool valid = true;
  for (int i = length - 2; i >= 0; --i) {
    int partial = num / ten[i];
    if ((partial >= 5 && partial % 6 != 1 && partial % 6 != 5) || !Prime(marked, partial)) {
      valid = false;
      break;
    }
  }
  if (valid) {
    primes.insert(num);
  }
}

int main() {
  freopen("sprime.in", "r", stdin);
  freopen("sprime.out", "w", stdout);

  int length;
  scanf("%d", &length);

  int* ten = new int[length + 1];
  ten[0] = 1;
  for (int i = 1; i <= length; ++i) {
    ten[i] = ten[i - 1] * 10;
  }

  int begin = ten[length - 1];
  int end = ten[length];
  std::set<int> primes;
  std::map<int, bool> marked;
  for (int i = begin / 100; i < end / 100; ++i) {
    int suffix[4] = {1, 3, 7, 9};
    for (int j = 0; j < 4; ++j) {
      Check(primes, marked, ten, length, ten[length - 1] * 2 + i * 10 + suffix[j]);
      Check(primes, marked, ten, length, ten[length - 1] * 3 + i * 10 + suffix[j]);
      Check(primes, marked, ten, length, ten[length - 1] * 5 + i * 10 + suffix[j]);
      Check(primes, marked, ten, length, ten[length - 1] * 7 + i * 10 + suffix[j]);
    }
  }

  for (auto it = primes.begin(); it != primes.end(); ++it) {
    printf("%d\n", *it);
  }

  return 0;
}
