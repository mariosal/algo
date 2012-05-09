#include <stdio.h>

int main() {
    short i, sum, N, apples[ 3 ], pie[ 3 ];

    freopen( "apple.in", "r", stdin );
    freopen( "apple.out", "w", stdout );

    scanf( "%hd %hd %hd %hd", &apples[ 0 ], &apples[ 1 ], &apples[ 2 ], &N );

    if ( apples[ 0 ] + apples[ 1 ] + apples[ 2 ] < N ) {
        puts( "-1" );

        return 0;
    }

    pie[ 0 ] = pie[ 1 ] = pie[ 2 ] = 0;
    for ( i = sum = 0; sum < N; ++i ) {
        if ( sum + apples[ i ] <= N ) {
            sum += apples[ i ];
            pie[ i ] = apples[ i ];
        }
        else {
            pie[ i ] = N - sum;
            sum += N - sum;
        }
    }

    printf( "%hd %hd %hd\n", pie[ 0 ], pie[ 1 ], pie[ 2 ] );

    return 0;
}
