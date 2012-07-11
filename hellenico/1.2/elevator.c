#include <stdio.h>
#include <stdlib.h>

int cmp( const void *a, const void *b ) {
  return *( int* )a - *( int* )b;
}

int main( void ) {
  int i, j, md, mw, N, *w;

  freopen( "elevator.in", "r", stdin );
  freopen( "elevator.out", "w", stdout );

  scanf( "%d", &N );
  w = ( int* )malloc( N * sizeof( int ) );

  for ( i = 0; i < N; i += 1 ) {
    scanf( "%d", &w[ i ] );
  }

  qsort( w, N, sizeof( int ), cmp );

  if ( N % 2 == 0 ) {
    md = N / 2;
    mw = w[ N - 1 ] + w[ 0 ];
    i = 1;
  }
  else {
    md = ( ( N - 1 ) / 2 ) + 1;
    mw = w[ N - 1 ];
    i = 0;
  }

  for ( j = N - 2; i < j; i += 1, j -= 1 ) {
    if ( mw < w[ i ] + w[ j ] ) {
      mw = w[ i ] + w[ j ];
    }
  }

  printf( "%d %d\n", md, mw );

  return 0;
}
