#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main() {
  const char N = 80;
  char i, j, k;
  short a[ N ][ N ];
  int sum, minW, w[ N ][ N ];

  for ( i = 0; i < N; ++i ) {
    for ( j = 0; j < N; ++j ) {
      scanf( "%hd", &a[ i ][ j ] );
      w[ i ][ j ] = 987654321;
    }
  }

  for ( i = 0; i < N; ++i ) {
    w[ i ][ 0 ] = a[ i ][ 0 ];
  }

  for ( j = 0; j < N - 1; ++j ) {
    for ( i = 0; i < N; ++i ) {
      sum = w[ i ][ j ];
      for ( k = i; k < N; ++k ) {
        sum += a[ k ][ j + 1 ];
        w[ k ][ j + 1 ] = min( w[ k ][ j + 1 ], sum );
      }

      sum = w[ i ][ j ];
      for ( k = i; k >= 0; --k ) {
        sum += a[ k ][ j + 1 ];
        w[ k ][ j + 1 ] = min( w[ k ][ j + 1 ], sum );
      }
    }
  }

  minW = 987654321;
  for ( i = 0; i < N; ++i ) {
    minW = min( minW, w[ i ][ N - 1 ] );
  }
  printf( "%d\n", minW );

  return 0;
}
