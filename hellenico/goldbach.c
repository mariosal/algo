#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *P;
    int N, i, j;

    freopen( "goldbach.in", "r", stdin );
    freopen( "goldbach.out", "w", stdout );

    scanf( "%d", &N );
    P = ( char* )malloc( N - 1 );
    memset( P, 1, N - 1 );

    for ( i = 2; i * i <= N; i += 1 ) {
        if ( P[ i - 1 ] ) {
            for ( j = i * i; j <= N; j += i ) {
                P[ j - 1 ] = 0;
            }
        }
    }

    for ( i = 2; i <= N; i += 1 ) {
        if ( P[ i - 1 ] && P[ N - i - 1 ] ) {
            printf( "%d %d\n", i, N - i );
            break;
        }
    }

    free( P );
    fclose( stdin );
    fclose( stdout );

    return 0;
}
