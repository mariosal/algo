#include <cstdio>
#include <cmath>
#include <set>

using namespace std;

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
    const int N = 50000000;
    const int primeN = 7070;
    bool *isPrime;
    int i, j, k, cntPrime, *prime;
    long sum;
    set< long > mark;

    isPrime = sieve( primeN );
    prime = new int[ primeN ];
    cntPrime = 0;
    for ( i = 2; i < primeN; ++i ) {
        if ( isPrime[ i ] ) {
            prime[ cntPrime ] = i;
            ++cntPrime;
        }
    }

    for ( i = 0; i < cntPrime; ++i ) {
        for ( j = 0; j < cntPrime; ++j ) {
            for ( k = 0; k < cntPrime; ++k ) {
                sum = ( long )prime[ i ] * prime[ i ];
                sum += ( long )prime[ j ] * prime[ j ] * prime[ j ];
                sum += ( long )prime[ k ] * prime[ k ] * prime[ k ] * prime[ k ];
                if ( sum >= N ) {
                    break;
                }

                mark.insert( sum );
            }
        }
    }
    printf( "%d\n", ( int )mark.size() );

    return 0;
}
