#include <stdio.h>
#include <stdlib.h>

int main() {
    char j;
    short change, i, value[ 6 ], *best;

    freopen( "resta.in", "r", stdin );
    freopen( "resta.out", "w", stdout );

    scanf( "%hd", &change );
    best = ( short* )malloc( ( change + 1 ) * sizeof( short ) );

    value[ 0 ] = 1;
    value[ 1 ] = 2;
    value[ 2 ] = 5;
    value[ 3 ] = 10;
    value[ 4 ] = 50;
    value[ 5 ] = 100;

    best[ 0 ] = 0;
    for ( i = 1; i <= change; i += 1 ) {
        best[ i ] = 7001;
    }

    for ( i = 1; i <= change; i += 1 ) {
        for ( j = 0; j < 6; j += 1 ) {
            if ( value[ j ] <= i ) {
                if ( best[ i ] > best[ i - value[ j ] ] + 1 ) {
                    best[ i ] = best[ i - value[ j ] ] + 1;
                }
            }
        }
    }

    printf( "%hd\n", best[ change ] );

    return 0;
}
