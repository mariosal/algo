#include <stdio.h>
#include <stdlib.h>

int min( int a, int b ) {
    return a < b ? a : b;
}

int main() {
    int i, j, q, N;
    int A[ 100000 ][ 3 ][ 2 ];

    //freopen( "in.txt", "r", stdin );

    for ( q = 1; ; ++q ) {
        scanf( "%d", &N );
        if ( !N ) {
            break;
        }

        for ( i = 0; i < N; ++i ) {
            for ( j = 0; j < 3; ++j ) {
                scanf( "%d", &A[ i ][ j ][ 0 ] );
                A[ i ][ j ][ 1 ] = 999999999;
            }
        }

        A[ 0 ][ 1 ][ 1 ] = 0;
        for ( i = 0; i < N; ++i ) {
            if ( i > 0 ) {
                A[ i ][ 0 ][ 1 ] += A[ i ][ 0 ][ 0 ];
                A[ i ][ 1 ][ 1 ] = min( A[ i ][ 0 ][ 1 ], A[ i ][ 1 ][ 1 ] );
                if ( i < N - 1 ) {
                    A[ i + 1 ][ 0 ][ 1 ] = min( A[ i ][ 0 ][ 1 ], A[ i + 1 ][ 0 ][ 1 ] );
                    A[ i + 1 ][ 1 ][ 1 ] = min( A[ i ][ 0 ][ 1 ], A[ i + 1 ][ 1 ][ 1 ] );
                }
            }

            A[ i ][ 1 ][ 1 ] += A[ i ][ 1 ][ 0 ];
            A[ i ][ 2 ][ 1 ] = min( A[ i ][ 1 ][ 1 ], A[ i ][ 2 ][ 1 ] );
            if ( i < N - 1 ) {
                A[ i + 1 ][ 0 ][ 1 ] = min( A[ i ][ 1 ][ 1 ], A[ i + 1 ][ 0 ][ 1 ] );
                A[ i + 1 ][ 1 ][ 1 ] = min( A[ i ][ 1 ][ 1 ], A[ i + 1 ][ 1 ][ 1 ] );
                A[ i + 1 ][ 2 ][ 1 ] = min( A[ i ][ 1 ][ 1 ], A[ i + 1 ][ 2 ][ 1 ] );
            }

            A[ i ][ 2 ][ 1 ] += A[ i ][ 2 ][ 0 ];
            if ( i < N - 1 ) {
                A[ i + 1 ][ 1 ][ 1 ] = min( A[ i ][ 2 ][ 1 ], A[ i + 1 ][ 1 ][ 1 ] );
                A[ i + 1 ][ 2 ][ 1 ] = min( A[ i ][ 2 ][ 1 ], A[ i + 1 ][ 2 ][ 1 ] );
            }
        }

        printf( "%d. %d\n", q, A[ N - 1 ][ 1 ][ 1 ] );
    }

    return 0;
}
