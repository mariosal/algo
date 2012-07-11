#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, sum, i, j, *value, *best, *backtrack;

  scanf( "%d %d", &n, &sum );

  value = ( int* )malloc( n * sizeof( int ) );
  best = ( int* )malloc( ( sum + 1 ) * sizeof( int ) );
  backtrack = ( int* )malloc( ( sum + 1 ) * sizeof( int ) );

  for ( i = 0; i < n; i += 1 ) {
    scanf( "%d", &value[ i ] );
  }

  best[ 0 ] = backtrack[ 0 ] = 0;
  for ( i = 1; i <= sum; i += 1 ) {
    best[ i ] = 987654321;
  }

  for ( i = 1; i <= sum; i += 1 ) {
    for ( j = 0; j < n; j += 1 ) {
      if ( value[ j ] <= i ) {
        if ( best[ i ] > best[ i - value[ j ] ] + 1 ) {
          best[ i ] = best[ i - value[ j ] ] + 1;
          backtrack[ i ] = value[ j ];
        }
      }
    }
  }

  for ( i = 1; i <= sum; i += 1 ) {
    printf( "Sum: %d. Coins: %d. Solution:", i, best[ i ] );
    j = i;
    while ( j > 0 ) {
      printf( " %d", backtrack[ j ] );
      j -= backtrack[ j ];
    }
    putchar( '\n' );
  }

  return 0;
}
