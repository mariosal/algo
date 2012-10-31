#include <cstdio>

int main() {
  char **s;
  short n, i, j, k, l, zero, one;

  freopen( "paso.in", "r", stdin );
  freopen( "paso.out", "w", stdout );

  scanf( "%hd\n", &n );
  s = new char*[ 3 * n ];
  for ( i = 0; i < 3 * n; ++i ) {
    s[ i ] = new char[ 3 * n ];
    for ( j = 0; j < 3 * n; ++j ) {
      scanf( "%c%*c", &s[ i ][ j ] );
    }
  }

  for ( i = 0; i < n; ++i ) {
    for ( j = 0; j < n; ++j ) {
      zero = 0;
      one = 0;

      for ( k = 3 * i; k < 3 * i + 3; ++k ) {
        for ( l = 3 * j; l < 3 * j + 3; ++l ) {
          if ( s[ k ][ l ] == '0' ) {
            ++zero;
          }
          else {
            ++one;
          }
        }
      }

      printf( "%c%c", zero > one ? '0' : '1', j == n - 1 ? '\n' : ' ' );
    }
  }

  return 0;
}
