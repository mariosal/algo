#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, i, j, min[ 2 ], *a;

    freopen( "operators.in", "r", stdin );
    freopen( "operators.out", "w", stdout );

    scanf( "%d", &n );
    a = ( int* )malloc( n * sizeof( int ) );

    for ( i = 0; i < n; i += 1 ) {
        scanf( "%d", &a[ i ] );
    }

    i = 0;
    j = n - 1;
    min[ 0 ] = a[ i ];
    min[ 1 ] = a[ j ];
    while ( i < j ) {
        if ( abs( min[ 0 ] + min[ 1 ] ) > abs( a[ i ] + a[ j ] ) ) {
            min[ 0 ] = a[ i ];
            min[ 1 ] = a[ j ];
            if ( a[ i ] + a[ j ] == 0 ) {
                break;
            }
        }
        if ( a[ i ] + a[ j ] > 0 ) {
            j -= 1;
        }
        else {
            i += 1;
        }
    }

    printf( "%d %d\n", min[ 0 ], min[ 1 ] );

    return 0;
}
