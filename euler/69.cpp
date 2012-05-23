#include <cstdio>
#include <cmath>

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

int phi( int n, int *prime, int cntPrime ) {
    int i;
    float product;

    product = 1;
    for ( i = 0; i < cntPrime; ++i ) {
        if ( prime[ i ] > n ) {
            break;
        }
        if ( n % prime[ i ] == 0 ) {
            product *= 1 - ( float )1 / prime[ i ];
        }
    }

    return ceil( n * product );
}

int main() {
    const int N = 1000000;
    bool *isPrime;
    int i, dummy, ans, cntPrime, *prime, *memo;
    float maxFraction;

    isPrime = sieve( N );
    prime = new int[ N ];
    cntPrime = 0;
    for ( i = 2; i <= N; ++i ) {
        if ( isPrime[ i ] ) {
            prime[ cntPrime ] = i;
            ++cntPrime;
        }
    }

    maxFraction = 2; // 2 / φ( 2 )
    for ( i = 2; i <= N; ++i ) {
        dummy = phi( i, prime, cntPrime );
        if ( maxFraction < ( float )i / dummy ) {
            maxFraction = ( float )i / dummy;
            ans = i;
        }
    }
    printf( "%d\n", ans );

    return 0;
}
