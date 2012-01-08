#include <stdio.h>

int Reverse( int n ) {
    int i = 0;

    while ( n > 0 ) {
        i = 10 * i + n % 10;
        n /= 10;
    }

    return i;
}

int n, p, r;

int main() {
    scanf( "%d", &n );

    while ( n-- ) {
        scanf( "%d %d", &p, &r );
        printf( "%d\n", Reverse( Reverse( p ) + Reverse( r ) ) );
    }

    return 0;
}
