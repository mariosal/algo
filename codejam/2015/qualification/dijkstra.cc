#include <cstdio>
#include <cstring>

using namespace std;

enum Quaternions {
  ONE = 0, I, J, K,
  MONE, MI, MJ, MK
};

Quaternions neg(Quaternions a) {
  Quaternions table[8] = {
    MONE, MI, MJ, MK,
    ONE, I, J, K
  };

  return table[a];
}

Quaternions mul(Quaternions a, Quaternions b) {
  Quaternions table[4][4] = {
    {ONE, I, J, K},
    {I, MONE, K, MJ},
    {J, MK, MONE, I},
    {K, J, MI, MONE}
  };

  if (a > K) {
    return neg(mul(neg(a), b));
  }
  if (b > K) {
    return neg(mul(a, neg(b)));
  }

  return table[a][b];
}

Quaternions inv(Quaternions a) {
  Quaternions table[8] = {
    ONE, MI, MJ, MK,
    MONE, I, J, K
  };

  return table[a];
}

Quaternions ToQ(char a) {
  switch (a) {
  case '1':
    return ONE;
  case 'i':
    return I;
  case 'j':
    return J;
  case 'k':
    return K;
  }
}

Quaternions *partial_prod;

Quaternions prod(int i, int j) {
  if (i == 0) {
    return partial_prod[j];
  }
  return mul(inv(prod(0, i - 1)), prod(0, j));
}

int main(void) {
  int test_cases;
  scanf("%d", &test_cases);

  for (int i = 1; i <= test_cases; ++i) {
    int l, x;
    scanf("%d %d", &l, &x);

    char *s = new char[l + 1];
    scanf("%s", s);

    partial_prod = new Quaternions[l * x];
    partial_prod[0] = ToQ(s[0]);
    for (int j = 1; j < l * x; ++j) {
      partial_prod[j] = mul(partial_prod[j - 1], ToQ(s[j % l]));
    }

    char ans[4] = "NO";
    if (l * x >= 3) {
      for (int j = 0; j <= l * x - 3; ++j) {
        for (int k = j + 1; k <= l * x - 2; ++k) {
          if (prod(0, j) == I && prod(j + 1, k) == J && prod(k + 1, l * x - 1) == K) {
            strcpy(ans, "YES");
            break;
          }
        }

        if (ans[0] == 'Y') {
          break;
        }
      }
    }

    printf("Case #%d: %s\n", i, ans);
  }

  return 0;
}
