#include <cstdio>

int main() {
  int i, n, d, *w;

  while ( scanf( "%d %d", &n, &d ) ) {
    if ( n == 0 ) {
      break;
    }

    w = new int[ n + 1 ];
    w[ 1 ] = 0;
    for ( i = 2; i <= n; ++i ) {
      w[ i ] = ( w[ i - 1 ] + d ) % i;
    }

    printf( "%d %d %d\n", n, d, w[ n ] + 1 );

    delete[] w;
  }

  return 0;
}
