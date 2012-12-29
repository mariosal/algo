#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

short pi( short n ) {
  return n / log( n );
}

int main() {
  char *isPrime, buffer[ 5 ];
  short dummy, cntPrime, *prime, perm[ 24 ];
  int i, j, k, l, m;
  set< short > memo;

  isPrime = new char[ 9999 + 1 ];
  isPrime[ 0 ] = 0;
  isPrime[ 1 ] = 0;
  for ( i = 2; i <= 9999; ++i ) {
    isPrime[ i ] = 1;
  }

  cntPrime = 0;
  prime = new short[ pi( 9999 ) ];
  for ( i = 2; i <= 9999; ++i ) {
    if ( isPrime[ i ] ) {
      if ( i > 999 ) {
        prime[ cntPrime ] = i;
        ++cntPrime;
      }
      for ( j = i * i; j <= 9999; j += i ) {
        isPrime[ j ] = 0;
      }
    }
  }

  for ( i = 0; i < cntPrime; ++i ) {
    if ( memo.find( prime[ i ] ) != memo.end() ) {
      continue;
    }

    sprintf( buffer, "%hd", prime[ i ] );
    j = 0;
    do {
      dummy = atoi( buffer );
      if ( isPrime[ dummy ] ) {
        perm[ j ] = atoi( buffer );
        memo.insert( perm[ j ] );
        ++j;
      }
    } while ( next_permutation( buffer, buffer + 4 ) );

    for ( k = 0; k < j; ++k ) {
      for ( l = k + 1; l < j; ++l ) {
        for ( m = l + 1; m < j; ++m ) {
          if ( perm[ k ] != perm[ l ] && perm[ k ] != perm[ m ] && perm[ l ] != perm[ m ] ) {
            if ( perm[ l ] - perm[ k ] == perm[ m ] - perm[ l ] ) {
              printf( "%d%d%d\n", perm[ k ], perm[ l ], perm[ m ] );
              m = j;
              l = j;
              k = j;
            }
          }
        }
      }
    }
  }

  return 0;
}
