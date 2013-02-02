#include <stdio.h>
#include <stdlib.h>

short min( short a, short b ) {
  return a < b ? a : b;
}

short max( short a, short b ) {
  return a > b ? a : b;
}

short i, N, p12, p13, p21, p23, p31, p32, ac[ 4 ], *a;

int main() {
  freopen( "sort3.in", "r", stdin );
  freopen( "sort3.out", "w", stdout );
  scanf( "%hd", &N );
  a = ( short* )malloc( N );

  for ( i = 0; i < N; ++i ) {
    scanf( "%hd", &a[ i ] );
    ++ac[ a[ i ] ];
  }

  for ( i = 0; i < ac[ 1 ]; ++i ) {
    if ( a[ i ] == 2 ) {
      ++p12;
    }
    else if ( a[ i ] == 3 ) {
      ++p13;
    }
  }
  for ( i = ac[ 1 ]; i < ac[ 1 ] + ac[ 2 ]; ++i ) {
    if ( a[ i ] == 1 ) {
      ++p21;
    }
    else if ( a[ i ] == 3 ) {
      ++p23;
    }
  }
  for ( i = ac[ 1 ] + ac[ 2 ]; i < ac[ 1 ] + ac[ 2 ] + ac[ 3 ]; ++i ) {
    if ( a[ i ] == 1 ) {
      ++p31;
    }
    else if ( a[ i ] == 2 ) {
      ++p32;
    }
  }

  printf( "%hd\n", min( p12, p21 ) + min( p13, p31 ) + min( p23, p32 ) + 2 * ( max( p12, p21 ) - min( p12, p21 ) ) );

  return 0;
}
