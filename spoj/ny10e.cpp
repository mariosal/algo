#include <cstdio>

int main() {
  char i, j, k;
  short l, t, n;
  long long ans, **w;

  scanf( "%hd", &t );
  for ( l = 1; l <= t; ++l ) {
    scanf( "%*d %hd", &n );

    w = new long long*[ 10 ];
    for ( i = 0; i <= 9; ++i ) {
      w[ i ] = new long long[ n ];
      w[ i ][ 0 ] = 1;
    }

    for ( i = 9; i >= 0; --i ) {
      for ( j = 1; j < n; ++j ) {
        w[ i ][ j ] = 0;
        for ( k = i; k <= 9; ++k ) {
          w[ i ][ j ] += w[ k ][ j - 1 ];
        }
      }
    }

    ans = 0;
    for ( i = 0; i <= 9; ++i ) {
      ans += w[ i ][ n - 1 ];
    }
    printf( "%hd %lld\n", l, ans );

    for ( i = 0; i <= 9; ++i ) {
      delete[] w[ i ];
    }
    delete[] w;
  }

  return 0;
}
