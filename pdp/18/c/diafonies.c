#include <stdio.h>
#include <stdlib.h>

void dfs( short *nSet0, short **E, char *set, short source ) {
    short i;

    for ( i = 1; i <= E[ source ][ 0 ]; ++i ) {
        if ( set[ E[ source ][ i ] ] == -1 ) {
            if ( set[ source ] ) {
                ++*nSet0;
            }
            set[ E[ source ][ i ] ] = !set[ source ];
            dfs( nSet0, E, set, E[ source ][ i ] );
        }
        else if ( set[ source ] == set[ E[ source ][ i ] ] ) {
            *nSet0 = -1;
            break;
        }
    }
}

int main() {
    char *set;
    short n, nSet0, neighbors, i, j, **E;

    scanf( "%hd", &n );
    E = ( short** )malloc( n * sizeof( short* ) );
    set = ( char* )malloc( n );

    for ( i = 0; i < n; ++i ) {
        scanf( "%*d %hd", &neighbors );
        E[ i ] = ( short* )malloc( ( neighbors + 1 ) * sizeof( short ) );

        set[ i ] = -1;
        E[ i ][ 0 ] = neighbors;
        for ( j = 1; j <= E[ i ][ 0 ]; ++j ) {
            scanf( "%hd", &E[ i ][ j ] );
            --E[ i ][ j ];
        }
    }

    nSet0 = 0;
    for ( i = 0; i < n; ++i ) {
        if ( set[ i ] == -1 ) {
            ++nSet0;
            ++set[ i ];
            dfs( &nSet0, E, set, i );
        }
    }

    if ( nSet0 == -1 ) {
        puts( "0\n0" );
        return 0;
    }

    printf( "%hd", nSet0 );
    for ( i = 0; i < n; ++i ) {
        if ( !set[ i ] ) {
            printf( " %hd", i + 1 );
        }
    }
    putchar( '\n' );

    printf( "%hd", n - nSet0 );
    for ( i = 0; i < n; ++i ) {
        if ( set[ i ] ) {
            printf( " %hd", i + 1 );
        }
    }
    putchar( '\n' );

    return 0;
}
