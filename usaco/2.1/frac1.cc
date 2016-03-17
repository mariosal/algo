/*
  ID: mariosa1
  TASK: frac1
  LANG: C++11
*/
#include <cstdio>
#include <set>

struct Fraction {
  bool operator<(const Fraction& frac) const {
    return n * frac.d < frac.n * d;
  }

  int n;
  int d;
};

static int Gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return Gcd(b, a % b);
}

int main() {
  freopen("frac1.in", "r", stdin);
  freopen("frac1.out", "w", stdout);

  int n;
  scanf("%d", &n);

  std::set<Fraction> fracs;
  for (int j = 1; j <= n; ++j) {
    for (int i = 0; i <= j; ++i) {
      if (Gcd(i, j) == 1) {
        fracs.insert({i, j});
      }
    }
  }

  for (auto it = fracs.begin(); it != fracs.end(); ++it) {
    printf("%d/%d\n", it->n, it->d);
  }
  return 0;
}
