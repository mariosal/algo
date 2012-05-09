#include <stdio.h>
#include <string.h>

int main() {
    char word[ 81 ];
    short N, M, i, j, len;

    //freopen( "in.txt", "r", stdin );

    scanf( "%hd", &N );
    for ( i = 1; i <= N; ++i ) {
        scanf( "%hd %s", &M, word );

        len = strlen( word );
        for ( j = M - 1; j <= len; ++j ) {
            word[ j ] = word[ j + 1 ];
        }

        printf( "%hd %s\n", i, word );
    }

    return 0;
}
