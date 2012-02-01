#include <stdio.h>
#include <stdlib.h>

void floyd( int **D, int V ) {
    int k, i, j;

    for ( k = 1; k <= V; k += 1 ) {
        for ( i = 1; i <= V; i += 1 ) {
            for ( j = 1; j <= V; j += 1 ) {
                if ( D[ i ][ j ] > D[ i ][ k ] + D[ k ][ j ] ) {
                    D[ i ][ j ] = D[ i ][ k ] + D[ k ][ j ];
                }
            }
        }
    }
}

int main() {
    int V, E, v, u, w, s, t, i, j, **D;

    freopen( "graph.in", "r", stdin );

    scanf( "%d %d %d %d", &V, &E, &s, &t );

    D = ( int** )malloc( ( V + 1 ) * sizeof( int* ) );
    for ( i = 1; i <= V; i += 1 ) {
        D[ i ] = ( int* )malloc( ( V + 1 ) * sizeof( int ) );
        for ( j = 1; j <= V; j += 1 ) {
            D[ i ][ j ] = 987654321;
        }
    }

    while ( E-- ) {
        scanf( "%d %d %d", &v, &u, &w );

        D[ v ][ u ] = w;
        D[ u ][ v ] = w;
    }

    floyd( D, V );
    printf( "%d\n", D[ s ][ t ] );

    return 0;
}
