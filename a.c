#include <stdio.h>

int main() {
    short i;

    freopen( "TEST", "r", stdin );

    for ( i = 1; i <= 1000; i += 1 ) {
        printf( "%hd\n", i );
    }

    fclose( stdin );

    return 0;
}
