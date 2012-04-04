#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int size;
} node;

int max( int a, int b ) {
    if ( a >= b ) {
        return a;
    }
    return b;
}

int main() {
    short n, maxSize, i, j;
    int **best;
    node *item;

    scanf( "%hd %hd", &maxSize, &n );

    item = ( node* )malloc( n * sizeof( node ) );
    best = ( int** )malloc( ( n + 1 ) * sizeof( int* ) );
    for ( i = 0; i <= n; ++i ) {
        best[ i ] = ( int* )malloc( ( maxSize + 1 ) * sizeof( int ) );
        best[ i ][ 0 ] = 0;
    }
    for ( i = 0; i <= maxSize; ++i ) {
        best[ 0 ][ i ] = 0;
    }

    for ( i = 0; i < n; ++i ) {
        scanf( "%d %d", &item[ i ].size, &item[ i ].value );
    }

    for ( i = 1; i <= maxSize; ++i ) {
        for ( j = 1; j <= n; ++j ) {
            if ( item[ j - 1 ].size <= i ) {
                best[ j ][ i ] = max( best[ j - 1 ][ i ], best[ j - 1 ][ i - item[ j - 1 ].size ] + item[ j - 1 ].value );
            }
            else {
                best[ j ][ i ] = best[ j - 1 ][ i ];
            }
        }
    }

    printf( "%d\n", best[ n ][ maxSize ] );

    return 0;
}
