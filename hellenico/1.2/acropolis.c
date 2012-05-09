#include <stdio.h>
#include <stdlib.h>

int cmp( const void *a, const void *b ) {
    return *( int* )a - *( int* )b;
}

int main( void ) {
    int i, j, q, N, nu, *w, *one;

    freopen( "acropolis.in", "r", stdin );
    freopen( "acropolis.out", "w", stdout );

    scanf( "%d", &N );
    w = ( int* )malloc( N * sizeof( int ) );
    one = ( int* )malloc( N * sizeof( int ) );

    q = 0;
    for ( i = 0; i < N; i += 1 ) {
        one[ i ] = 0;
        scanf( "%d", &j );
        if ( j == 1 ) {
            one[ i ] = 1;
        }
        else {
            w[ q ] = j;
            q += 1;
        }
    }

    qsort( w, q, sizeof( int ), cmp );

    q = 0;
    for ( i = 0; i < N; i += 1 ) {
        if ( one[ i ] == 1 ) {
            nu = 1;
        }
        else {
            nu = w[ q ];
            q += 1;
        }
        printf( "%d\n", nu );
    }

    return 0;
}
