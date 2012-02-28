#include <stdio.h>
#include <stdlib.h>

int **cut( int *p, int n ) {
    int i, j, cost, **r;

    r = ( int** )malloc( ( n + 1 ) * sizeof( int* ) );
    for ( i = 0; i <= n; i += 1 ) {
        r[ i ] = ( int* )malloc( 2 * sizeof( int ) );
    }

    r[ 0 ][ 0 ] = 0;
    r[ 0 ][ 1 ] = 0;
    for ( i = 1; i <= n; i += 1 ) {
        cost = -1;
        for ( j = 1; j <= i; j += 1 ) {
            if ( cost < p[ j ] + r[ i - j ][ 0 ] ) {
                cost = p[ j ] + r[ i - j ][ 0 ];
                r[ i ][ 1 ] = j;
            }
        }
        r[ i ][ 0 ] = cost;
    }

    return r;
}

int main() {
    int i, j, n, *p, **r;

    scanf( "%d", &n );
    p = ( int* )malloc( ( n + 1 ) * sizeof( int ) );

    for ( i = 1; i <= n; i += 1 ) {
        scanf( "%d", &p[ i ] );
    }

    r = cut( p, n );
    for ( i = 1; i <= n; i += 1 ) {
        printf( "Length: %d Revenue: %d Solution: ", i, r[ i ][ 0 ] );
        j = i;
        while ( j > 0 ) {
            printf( "%d ", r[ j ][ 1 ] );
            j -= r[ j ][ 1 ];
        }
        putchar( '\n' );
    }

    return 0;
}
