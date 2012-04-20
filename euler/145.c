#include <stdio.h>
#include <math.h>

int reverse( int n ) {
    char i, len, a, b;
    int down, up;

    len = floor( log10( n ) ) + 1;
    down = pow( 10, len - 1 );
    up = 1;
    for ( i = 0; i < len / 2; ++i ) {
        a = n / down % 10;
        b = n / up % 10;

        n -= ( int )a * down;
        n += ( int )b * down;

        n -= b * up;
        n += a * up;

        down /= 10;
        up *= 10;
    }
    return n;
}

char hasOdd( int n ) {
    while ( n ) {
        if ( ( n % 10 ) % 2 == 0 ) {
            return 0;
        }
        n /= 10;
    }
    return 1;
}

int main() {
    const int N = 1000000000;
    int i, ans;

    ans = 0;
    for ( i = 1; i < N; ++i ) {
        if ( hasOdd( i + reverse( i ) ) && floor( log10( i ) ) == floor( log10( reverse( i ) ) ) ) {
            ++ans;
        }
    }
    printf( "%d\n", ans );

    return 0;
}
