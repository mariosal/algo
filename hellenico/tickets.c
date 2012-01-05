#include <stdio.h>

int main() {
    short i, j, q, num[ 5 ], dis[ 5 ] = { 0, 1, 2, 3, 5 };
    unsigned short price;

    freopen( "tickets.in", "r", stdin );
    freopen( "tickets.out", "w", stdout );

    scanf( "%hd\n%hd %hd %hd %hd", &j, &num[ 1 ], &num[ 2 ], &num[ 3 ], &num[ 4 ] );

    for ( i = 4; num[ i ] > j; i -= 1 );

    price = j * ( 10 - dis[ i ] );
    for ( i += 1; i <= 4; i += 1 ) {
        q = num[ i ] * ( 10 - dis[ i ] );
        if ( price > q ) {
            price = q;
        }
    }

    printf( "%hu\n", price );

    fclose( stdin );
    fclose( stdout );

    return 0;
}
