#include <stdio.h>

#define N 20

int main() {
  char i, j;
  long dp[ N + 1 ][ N + 1 ];

  for ( i = 0; i <= N; ++i ) {
    for ( j = 0; j <= N; ++j ) {
      dp[ i ][ j ] = 0;
    }
  }

  dp[ 0 ][ 0 ] = 1;
  for ( i = 0; i <= N; ++i ) {
    for ( j = 0; j <= N; ++j ) {
      if ( i < N ) {
        dp[ i + 1 ][ j ] += dp[ i ][ j ];
      }
      if ( j < N ) {
        dp[ i ][ j + 1 ] += dp[ i ][ j ];
      }
    }
  }
  dp[ 0 ][ 0 ] = 0;

  printf( "%ld\n", dp[ N ][ N ] );

  return 0;
}
