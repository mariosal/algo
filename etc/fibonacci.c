#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, i, *fib;

  scanf( "%d", &n );
  fib = ( int* )malloc( ( n + 1 ) * sizeof( int ) );

  fib[ 0 ] = 0;
  fib[ 1 ] = 1;
  for ( i = 2; i <= n; ++i ) {
    fib[ i ] = fib[ i - 1 ] + fib[ i - 2 ];
  }

  printf( "%d\n", fib[ n ] );

  return 0;
}
