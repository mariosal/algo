#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int rotate( int n ) {
    char len;

    len = floor( log10( n ) ) + 1;
    return ( n / 10 ) + ( n % 10 ) * pow( 10, len - 1 );
}

int main() {
    const int N = 1000000;
    char q, *prime;
    int i, j, ans;

    prime = ( char* )malloc( N );
    for ( i = 0; i < N; ++i ) {
        prime[ i ] = 1;
    }

    prime[ 0 ] = 0;
    prime[ 1 ] = 0;
    for ( i = 2; i * i < N; ++i ) {
        if ( prime[ i ] ) {
            for ( j = i * i; j < N; j += i ) {
                prime[ j ] = 0;
            }
        }
    }

    ans = 0;
    for ( i = 2; i < N; ++i ) {
        if ( prime[ i ] ) {
            q = 0;
            j = rotate( i );
            while ( prime[ j ] && q < floor( log10( i ) ) && floor( log10( j ) ) == floor( log10( i ) ) ) {
                j = rotate( j );
                ++q;
            }

            if ( q == floor( log10( i ) ) ) {
                ++ans;
            }
        }
    }
    printf( "%d\n", ans );

    return 0;
}
