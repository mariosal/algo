#include <stdio.h>
#include <stdlib.h>

int asc( const void *a, const void *b ) {
    return *( int* )a - *( int* )b;
}
int dsc( const void *a, const void *b ) {
    return *( int* )b - *( int* )a;
}

int main() {
    short T, n, casenum, i;
    int *v, *u;
    long long dot;

    scanf( "%hd", &T );

    casenum = 1;
    while ( T-- ) {
        scanf( "%hd", &n );

        v = ( int* )malloc( n * sizeof( int ) );
        u = ( int* )malloc( n * sizeof( int ) );

        for ( i = 0; i < n; i += 1 ) {
            scanf( "%d", &v[ i ] );
        }
        for ( i = 0; i < n; i += 1 ) {
            scanf( "%d", &u[ i ] );
        }

        qsort( v, n, sizeof( int ), asc );
        qsort( u, n, sizeof( int ), dsc );

        dot = 0;
        for ( i = 0; i < n; i += 1 ) {
            dot += ( long long )v[ i ] * u[ i ];
        }

        printf( "Case #%hd: %lld\n", casenum, dot );
        casenum += 1;
    }

    return 0;
}
