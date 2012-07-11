#include <cstdio>

int main() {
  int i, j, w[ 101 ];

  for ( i = 0; i <= 100; ++i ) {
    w[ i ] = 0;
  }
  
  w[ 0 ] = 1;
  for ( i = 1; i < 100; ++i ) {
    for ( j = i; j <= 100; ++j ) {
      w[ j ] += w[ j - i ];
    }
  }
  printf( "%d\n", w[ 100 ] );

  return 0;
}
