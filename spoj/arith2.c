#include <stdio.h>

int main() {
  char operator;
  long long n, a, res;

  scanf( "%lld", &n );
  while ( n-- ) {
    operator = 0;
    scanf( "%lld", &res );
    while ( 1 ) {
      scanf( "%s", &operator );
      if ( operator == '=' ) {
        break;
      }

      scanf( "%lld", &a );
      switch ( operator ) {
        case '+':
          res += a;
          break;
        case '-':
          res -= a;
          break;
        case '*':
          res *= a;
          break;
        case '/':
          res /= a;
          break;
      }
    }
    printf( "%lld\n", res );
  }

  return 0;
}
