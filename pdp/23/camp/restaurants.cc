#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int i, j, n, w0, w1, w11;
  short **a;

  scanf( "%d", &n );

  a = new short*[ n ];
  for ( i = 0; i < n; ++i ) {
    a[ i ] = new short[ 3 ];
  }

  for ( i = 0; i < n; ++i ) {
    scanf( "%hd", &a[ i ][ 0 ] );
  }
  for ( i = 0; i < n; ++i ) {
    scanf( "%hd", &a[ i ][ 1 ] );
  }
  a[ 0 ][ 2 ] = a[ n - 1 ][ 2 ] = 0;
  for ( i = 1; i < n - 1; ++i ) {
    scanf( "%hd", &a[ i ][ 2 ] );
  }

  w0 = 0;
  w1 = a[ 0 ][ 0 ];
  w11 = a[ 0 ][ 1 ];
  for ( i = 1; i < n; ++i ) {
    j = w1;
    w1 = max( w0 + a[ i ][ 0 ], w11 + a[ i ][ 1 ] );
    w11 = max( w0 + a[ i ][ 1 ], w11 + a[ i ][ 2 ] );
    w0 = max( w0, j );
  }
  printf( "%d\n", max( w0, w1 ) );

  return 0;
}
