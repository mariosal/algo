#include <cstdio>
#include <cmath>

using namespace std;

int pi( int n ) {
    return n / log( n );
}
int omega( int n, int *prime, int cntPrime ) {
    int i, ret;

    ret = 0;
    for ( i = 0; i < cntPrime; ++i ) {
        if ( n % prime[ i ] == 0 ) {
            ++ret;
        }
    }
    return ret;
}

int main() {
    const int N = 150000;
    char *isPrime;
    int i, j, cntPrime, *prime;

    isPrime = new char[ N + 1 ];
    isPrime[ 0 ] = 0;
    isPrime[ 1 ] = 0;
    for ( i = 2; i <= N; ++i ) {
        isPrime[ i ] = 1;
    }

    prime = new int[ N ];
    for ( i = 2; i * i <= N; ++i ) {
        if ( isPrime[ i ] ) {
            for ( j = i * i; j <= N; j += i ) {
                isPrime[ j ] = 0;
            }
        }
    }

    cntPrime = 0;
    for ( i = 2; i <= N; ++i ) {
        if ( isPrime[ i ] ) {
            prime[ cntPrime ] = i;
            ++cntPrime;
        }
    }

    for ( i = 2; i <= N - 3; ++i ) {
        if ( omega( i, prime, cntPrime ) == 4 &&
             omega( i + 1, prime, cntPrime ) == 4 &&
             omega( i + 2, prime, cntPrime ) == 4 &&
             omega( i + 3, prime, cntPrime ) == 4 ) {
            printf( "%d\n", i );
            break;
        }
    }

    return 0;
}
