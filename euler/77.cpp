#include <cstdio>
#include <cstdlib>

int main() {
  int i, j, cntPrime, *prime, *isPrime, *w;
  const int N = 5000;

  prime = new int[ N + 1 ];
  isPrime = new int[ N + 1 ];
  for ( i = 0; i <= N; ++i ) {
    prime[ i ] = 0;
    isPrime[ i ] = 1;
  }

  cntPrime = 0;
  isPrime[ 0 ] = 0;
  isPrime[ 1 ] = 0;
  for ( i = 2; i <= N; ++i ) {
    if ( isPrime[ i ] ) {
      prime[ cntPrime ] = i;
      ++cntPrime;
      for ( j = i * i; j <= N; j += i ) {
        isPrime[ j ] = 0;
      }
    }
  }

  w = new int[ N + 1 ];
  for ( i = 0; i <= N; ++i ) {
    w[ i ] = 0;
  }
  
  w[ 0 ] = 1;
  for ( i = 0; i < cntPrime; ++i ) {
    for ( j = prime[ i ]; j <= N; ++j ) {
      w[ j ] += w[ j - prime[ i ] ];
    }
  }
  for ( i = 0; i <= N; ++i ) {
    if ( w[ i ] > 5000 ) {
      printf( "%d\n", i );
      break;
    }
  }

  return 0;
}
