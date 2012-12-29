#include <cstdio>
#include <cmath>

int main() {
  const int N = 26500;
  char *isPrime;
  int i, j, sum, upRight, upLeft, downLeft, downRight;
  float ratio;

  isPrime = new char[ N * N + 1 ];
  for ( i = 0; i <= N * N; ++i ) {
    isPrime[ i ] = 1;
  }

  isPrime[ 0 ] = 0;
  isPrime[ 1 ] = 0;
  for ( i = 2; i <= N; ++i ) {
    if ( isPrime[ i ] ) {
      for ( j = i * i; j <= N * N; j += i ) {
        isPrime[ j ] = 0;
      }
    }
  }

  sum = 0;
  for ( i = 3; i <= N; i += 2 ) {
    upRight   = i * i;
    upLeft  = upRight -( i - 1 );
    downLeft  = upLeft -( i - 1 );
    downRight = downLeft -( i - 1 );

    sum += isPrime[ upRight ] + isPrime[ upLeft ] + isPrime[ downLeft ] + isPrime[ downRight ];

    ratio = ( float )sum / ( ( i / 2 ) * 4 + 1 );
    if ( ratio < 0.1 ) {
      printf( "%d\n", i );
      break;
    }
  }

  return 0;
}
