#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
  char a[ 2001 ], b[ 2001 ];
  short t, n, m, i, j, **w;

  scanf( "%hd", &t );
  while ( t-- ) {
    scanf( "%s %s", a, b );

    n = strlen( a );
    m = strlen( b );

    w = new short*[ n + 1 ];
    for ( i = 0; i <= n; ++i ) {
      w[ i ] = new short[ m + 1 ];
    }

    for ( i = 0; i <= n; ++i ) {
      w[ i ][ 0 ] = i;
    }
    for ( i = 0; i <= m; ++i ) {
      w[ 0 ][ i ] = i;
    }

    for ( i = 1; i <= n; ++i ) {
      for ( j = 1; j <= m; ++j ) {
        if ( a[ i - 1 ] == b[ j - 1 ] ) {
          w[ i ][ j ] = w[ i - 1 ][ j - 1 ];
        }
        else {
          w[ i ][ j ] = min( w[ i - 1 ][ j ], min( w[ i ][ j - 1 ], w[ i - 1 ][ j - 1 ] ) ) + 1;
        }
      }
    }
    printf( "%hd\n", w[ n ][ m ] );

    for ( i = 0; i <= n; ++i ) {
      delete[] w[ i ];
    }
    delete[] w;
  }

  return 0;
}
