#include <stdio.h>
#include <stdlib.h>

int main() {
    short N, **D, w, i, j, T;
    int unreducted, reducted, out, in;

    //freopen( "in.txt", "r", stdin );

    for ( T = 1; ; T += 1 ) {
        scanf( "%hd", &N );
        if ( !N ) {
            break;
        }

        unreducted = 0;
        D = ( short** )malloc( N * sizeof( short* ) );
        for ( i = 0; i < N; i += 1 ) {
            D[ i ] = ( short* )malloc( N * sizeof( short ) );
            for ( j = 0; j < N; j += 1 ) {
                scanf( "%hd", &D[ i ][ j ] );
                unreducted += D[ i ][ j ];
            }
        }

        reducted = 0;
        for ( i = 0; i < N; i += 1 ) {
            in = out = 0;
            for ( j = 0; j < N; j += 1 ) {
                out += D[ i ][ j ];
                in += D[ j ][ i ];
            }
            if ( out - in > 0 ) {
                reducted += out - in;
            }
        }

        printf( "%d. %d %d\n", T, unreducted, reducted );
    }

    return 0;
}
