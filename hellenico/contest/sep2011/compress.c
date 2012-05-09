#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char command, string[ 100001 ], compressed[ 100001 ];
    int i, j, q, len, sum, numcompressed[ 100000 ];

    freopen( "compress.in", "r", stdin );
    freopen( "compress.out", "w", stdout );

    scanf( "%c\n%s", &command, string );
    len = strlen( string );

    if ( command == 'D' ) {
        for ( i = 0; i < len; i += 1 ) {
            j = 0;
            while ( isdigit( string[ i ] ) ) {
                j *= 10;
                j += string[ i ] - '0';
                i += 1;
            }

            while ( j-- ) {
                putchar( string[ i ] );
            }
        }
    }
    else {
        for ( i = q = 0; q < len; ++i ) {
            compressed[ i ] = string[ q ];

            for ( sum = 0; compressed[ i ] == string[ q ]; ++q, ++sum );

            numcompressed[ i ] = sum;
        }

        for ( j = 0; j < i; ++j ) {
            printf( "%d%c", numcompressed[ j ], compressed[ j ] );
        }
    }

    putchar( '\n' );

    return 0;
}
