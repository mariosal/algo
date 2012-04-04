#include <stdio.h>
#include <stdlib.h>

typedef struct {
    short value;
    short size;
} node;

short max( short a, short b ) {
    if ( a > b ) {
        return a;
    }
    return b;
}

int main() {
    short i, j, n, size, **best;
    node *item;

    while ( 1 ) {
        scanf( "%hd %hd", &size, &n );
        if ( size == 0 && n == 0 ) {
            break;
        }

        item = ( node* )malloc( n * sizeof( node ) );
        for ( i = 0; i < n; ++i ) {
            scanf( "%hd %hd", &item[ i ].size, &item[ i ].value );
        }

        best = ( short** )malloc( ( n + 1 ) * sizeof( short* ) );
        for ( i = 0; i <= n; ++i ) {
            best[ i ] = ( short* )malloc( ( size + 1 ) * sizeof( short ) );
            best[ i ][ 0 ] = 0;
        }
        for ( i = 0; i <= size; ++i ) {
            best[ 0 ][ i ] = 0;
        }

        for ( i = 1; i <= size; ++i ) {
            for ( j = 1; j <= n; ++j ) {
                if ( item[ j - 1 ].size <= i ) {
                    best[ j ][ i ] = max( best[ j - 1 ][ i ], best[ j - 1 ][ i - item[ j - 1 ].size ] + item[ j - 1 ].value );
                }
                else {
                    best[ j ][ i ] = best[ j - 1 ][ i ];
                }
            }
        }

        for ( i = size; i > 0; --i ) {
            if ( best[ n ][ i ] != best[ n ][ i - 1 ] ) {
                printf( "%hd %hd\n", i, best[ n ][ i ] );
                break;
            }
        }

        for ( i = 0; i <= n; ++i ) {
            free( best[ i ] );
        }
        free( best );
        free( item );
    }

    return 0;
}
