#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  char i, j, k;
  short n;
  int l, m, *low, *up, ans, *a, *s;

  scanf( "%hd", &n );
  s = new int[ n ];
  for ( i = 0; i < n; ++i ) {
    scanf( "%d", s + i );
  }

  l = 0;
  a = new int[ n * n * n ];
  for ( i = 0; i < n; ++i ) {
    for ( j = 0; j < n; ++j ) {
      for ( k = 0; k < n; ++k ) {
        a[ l++ ] = s[ i ] * s[ j ] + s[ k ];
      }
    }
  }
  sort( a, a + l );

  ans = 0;
  for ( i = 0; i < n; ++i ) {
    for ( j = 0; j < n; ++j ) {
      for ( k = 0; k < n; ++k ) {
        if ( s[ i ] ) {
          m = s[ i ] * ( s[ j ] + s[ k ] );
          low = lower_bound( a, a + l, m );
          up = upper_bound( a, a + l, m );

          if ( *low == m ) {
            ans += ( int )( up - low );
          }
        }
      }
    }
  }
  printf( "%d\n", ans );

  return 0;
}
