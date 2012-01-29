#include <stdio.h>

int main() {
    short N, C, I, P[ 2000 ], i, j, casenum;

    scanf( "%hd", &N );

    casenum = 1;
    while ( N-- ) {
        scanf( "%hd\n%hd", &C, &I );

        for ( i = 0; i < I; i += 1 ) {
            scanf( "%hd", &P[ i ] );
        }

        for ( i = 0; i < I; i += 1 ) {
            for ( j = i + 1; j < I; j += 1 ) {
                if ( P[ i ] + P[ j ] == C ) {
                    printf( "Case #%hd: %hd %hd\n", casenum, i + 1, j + 1 );
                    i = I;
                    break;
                }
            }
        }

        casenum += 1;
    }

    return 0;
}
