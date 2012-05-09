#include <stdio.h>

int main() {
    short a1, a2, a3;

    while ( 1 ) {
        scanf( "%hd %hd %hd", &a1, &a2, &a3 );
        if ( a1 == 0 && a2 == 0 && a3 == 0 ) {
            break;
        }

        if ( a3 == 2 * a2 - a1 ) {
            printf( "AP %hd\n", a3 + a2 - a1 );
        }
        else {
            printf( "GP %d\n", a3 * a2 / a1 );
        }
    }

    return 0;
}
