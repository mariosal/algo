#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPermutation( int a, int b ) {
  char *aa, *bb, cntA, cntB;

  cntA = log10( a ) + 1;
  cntB = log10( b ) + 1;
  if ( cntA != cntB ) {
    return false;
  }

  aa = new char[ cntA + 1 ];
  bb = new char[ cntB + 1 ];
  sprintf( aa, "%d", a );
  sprintf( bb, "%d", b );

  sort( aa, aa + cntA + 1 );
  sort( bb, bb + cntB + 1 );

  return equal( aa, aa + cntA + 1, bb );
}

bool *sieve( int n ) {
  bool *isPrime;
  int i, j;

  isPrime = new bool[ n + 1 ];
  isPrime[ 0 ] = false;
  isPrime[ 1 ] = false;
  for ( i = 2; i <= n; ++i ) {
    isPrime[ i ] = true;
  }
  for ( i = 2; i * i <= n; ++i ) {
    if ( isPrime[ i ] ) {
      for ( j = i * i; j <= n; j += i ) {
        isPrime[ j ] = false;
      }
    }
  }

  return isPrime;
}

int main() {
  const int N = 10000000 - 1;
  bool *isPrime;
  int i, j, dummy, ans, cntPrime, *prime;
  float minFraction;

  isPrime = sieve( N );
  prime = new int[ N ];
  cntPrime = 0;
  for ( i = 2; i <= N; ++i ) {
    if ( isPrime[ i ] ) {
      prime[ cntPrime ] = i;
      ++cntPrime;
    }
  }

  ans = 0;
  minFraction = 2; // 2 / φ( 2 )
  for ( i = 0; i < cntPrime; ++i ) {
    for ( j = 0; j < cntPrime; ++j ) {
      if ( prime[ i ] * prime[ j ] > N ) {
        break;
      }

      dummy = ( prime[ i ] - 1 ) * ( prime[ j ] - 1 );
      if ( isPermutation( prime[ i ] * prime[ j ], dummy ) ) {
        if ( minFraction > ( float )prime[ i ] * prime[ j ] / dummy ) {
          minFraction = ( float )prime[ i ] * prime[ j ] / dummy;
          ans = prime[ i ] * prime[ j ];
        }
      }
    }
  }
  printf( "%d\n", ans );

  return 0;
}
