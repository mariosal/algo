#include <stdio.h>

int main() {
  char operator[2];
  long long n, a, res;

  scanf( "%lld", &n );
  while ( n-- ) {
    operator[0] = '\0';
    scanf( "%lld", &res );
    while ( 1 ) {
      scanf( "%s", operator );
      if ( operator[0] == '=' ) {
        break;
      }

      scanf( "%lld", &a );
      switch ( operator[0] ) {
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
