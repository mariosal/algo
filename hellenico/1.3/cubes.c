#include <stdio.h>

int a[ 100001 ];

int main() {
    int i, j, N, K;

    freopen( "cubes.in", "r", stdin );
    freopen( "cubes.out", "w", stdout );

    scanf( "%d %d", &N, &K );

    a[ 0 ] = N;
    j = 1;
    while ( a[ 0 ] - a[ 1 ] > K ) {
        for ( i = 0; i < j; ++i ) {
            if ( a[ i ] - a[ i + 1 ] > K ) {
                --a[ i ];
                ++a[ i + 1 ];
            }
            if ( a[ j ] ) {
                ++j;
            }
        }
    }

    printf( "%d\n", a[ 0 ] );

    fclose( stdin );
    fclose( stdout );

    return 0;
}
