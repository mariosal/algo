#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

vector< bool > sieve( short n ) {
  short i, j;
  vector< bool > isPrime( n + 1, true );

  isPrime[ 0 ] = false;
  isPrime[ 1 ] = false;
  for ( i = 2; i * i <= n; ++i ) {
    if ( isPrime[ i ] ) {
      for ( j = i * i; j <= n; j += i ) {
        isPrime[ j ] = false;
      }
    }
  }
  return isPrime;
}

bool check( int n, short *primes, short cntPrimes ) {
  short i;

  for ( i = 0; i < cntPrimes; ++i ) {
    if ( primes[ i ] * primes[ i ] > n ) {
      break;
    }
    if ( n == primes[ i ] ) {
      return true;
    }
    if ( n % primes[ i ] == 0 ) {
      return false;
    }
  }
  return true;
}

int main() {
  const int MAX = 1000000000;
  short t, i, j, cntPrimes, *primes;
  int n, m;
  vector< bool > isPrime;

  isPrime = sieve( sqrt( MAX ) );

  cntPrimes = 0;
  for ( i = 0; i < isPrime.size(); ++i ) {
    if ( isPrime[ i ] ) {
      ++cntPrimes;
    }
  }

  j = 0;
  primes = new short[ cntPrimes ];
  for ( i = 0; i < isPrime.size(); ++i ) {
    if ( isPrime[ i ] ) {
      primes[ j++ ] = i;
    }
  }

  scanf( "%hd", &t );
  while ( t-- ) {
    scanf( "%d %d", &m, &n );
    for ( ; m <= n; ++m ) {
      if ( m == 0 || m == 1 ) {
        continue;
      }

      if ( check( m, primes, cntPrimes ) ) {
        printf( "%d\n", m );
      }
    }

    printf( "\n" );
  }

  return 0;
}
