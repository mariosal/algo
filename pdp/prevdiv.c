#include <stdio.h>

int lcm( int a, int b ) {
    int step;

    if ( a > b ) {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    for ( step = b; b % a; b += step );

    return b;
}

int main() {
    int n, i, j, max;

    freopen( "prevdiv.in", "r", stdin );
    //freopen( "prevdiv.out", "w", stdout );

    scanf( "%d", &n );
    i = 1;
    while ( n-- ) {
        scanf( "%d", &j );

        i = lcm( i, j );
        if ( i == j ) {
            max = j;
        }

        if ( i == 2000000000 ) {
            break;
        }
    }
    printf( "%d\n", max );

    return 0;
}
