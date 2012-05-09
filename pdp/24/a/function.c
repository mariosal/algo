#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char space, *prime;
    short low, high, temp, i, j;

    freopen( "function.in", "r", stdin );
    freopen( "function.out", "w", stdout );

    scanf( "%hd %hd", &low, &high );
    if ( low > high ) {
        temp = low;
        low = high;
        high = temp;
    }

    if ( low != high ) {
        prime = ( char* )malloc( high - 3 );
        memset( prime, 1, high - 3 );

        for ( i = 3; i * i < high; i += 2 ) {
            if ( prime[ i - 3 ] ) {
                for ( j = i * i; j < high; j += 2 * i ) {
                    prime[ j - 3 ] = 0;
                }
            }
        }

        space = 0;
        for ( i = low % 2 ? low + 2 : low + 1; i < high; i += 2 ) {
            if ( prime[ i - 3 ] ) {
                if ( space ) {
                    putchar( ' ' );
                }
                else {
                    space = 1;
                }

                printf( "%hd", i );
            }
        }
        if ( space ) {
            putchar( '\n' );
        }
    }

    return 0;
}
