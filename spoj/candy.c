#include <stdio.h>

int main() {
  short i, N, A[ 10000 ];
  int sum, total;

  while ( 1 ) {
    scanf( "%hd", &N );
    if ( N == -1 ) {
      break;
    }

    for ( i = sum = 0; i < N; ++i ) {
      scanf( "%hd", &A[ i ] );

      sum += A[ i ];
    }

    if ( sum % N ) {
      puts( "-1" );
    }
    else {
      for ( i = total = 0; i < N; ++i ) {
        if ( A[ i ] > sum / N ) {
          total += A[ i ] - sum / N;
        }
      }

      printf( "%d\n", total );
    }
  }

  return 0;
}
