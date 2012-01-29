#include <stdio.h>
#include <stdlib.h>

int main() {
    char c, **string;
    short N, i, casenum;

    scanf( "%hd", &N );

    string = ( char** )malloc( 1000 * sizeof( char* ) );
    for ( i = 0; i < 1000; i += 1 ) {
        string[ i ] = ( char* )malloc( 1001 );
    }

    casenum = 1;
    while ( N-- ) {
        i = 0;
        do {
            scanf( "%s", string[ i ] );
            scanf( "%c", &c );
            i += 1;
        } while ( c != '\n' );

        printf( "Case #%d: ", casenum );
        while ( i-- ) {
            printf( "%s", string[ i ] );
            if ( i != 0 ) {
                putchar( ' ' );
            }
        }
        putchar( '\n' );

        casenum += 1;
    }

    return 0;
}
