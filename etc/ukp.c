#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int size;
} node;

int main() {
    int n, maxSize, i, j, *best, *backtrack;
    node *item;

    scanf( "%d %d", &n, &maxSize );

    item = ( node* )malloc( n * sizeof( node ) );
    best = ( int* )calloc( maxSize + 1, sizeof( int ) );
    backtrack = ( int* )malloc( ( maxSize + 1 ) * sizeof( int ) );

    for ( i = 0; i < n; i += 1 ) {
        scanf( "%d %d", &item[ i ].size, &item[ i ].value );
    }

    backtrack[ 0 ] = 0;
    for ( i = 1; i <= maxSize; i += 1 ) {
        for ( j = 0; j < n; j += 1 ) {
            if ( item[ j ].size <= i ) {
                if ( best[ i ] < best[ i - item[ j ].size ] + item[ j ].value ) {
                    best[ i ] = best[ i - item[ j ].size ] + item[ j ].value;
                    backtrack[ i ] = item[ j ].size;
                }
            }
        }
    }

    for ( i = 1; i <= maxSize; i += 1 ) {
        printf( "%d:", best[ i ] );
        j = i;
        while ( j > 0 ) {
            printf( " %d", backtrack[ j ] );
            j -= backtrack[ j ];
        }
        putchar( '\n' );
    }

    return 0;
}
