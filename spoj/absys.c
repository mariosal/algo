#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char len( int n ) {
    char i = 0;
    while ( n ) {
        n /= 10;
        ++i;
    }

    return i;
}

int main() {
    char sa[ 18 ], sb[ 18 ], sc[ 18 ];
    int T, a, b, c;

    //freopen( "in.txt", "r", stdin );

    scanf( "%d", &T );
    while ( T-- ) {
        scanf( "%s %*c %s %*c %s", sa, sb, sc );

        a = strlen( sa ) == len( atoi( sa ) ) ? atoi( sa ) : 0;
        b = strlen( sb ) == len( atoi( sb ) ) ? atoi( sb ) : 0;
        c = atoi( sc );

        if ( !a ) {
            printf( "%d + %d = %d\n", c - b, b, c );
        }
        else if ( !b ) {
            printf( "%d + %d = %d\n", a, c - a, c );
        }
        else {
            printf( "%d + %d = %d\n", a, b, a + b );
        }
    }

    return 0;
}
