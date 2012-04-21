#include <stdio.h>
#include <math.h>

int reverse( int n ) {
    int i;
    i = 0;
    while ( n ) {
        i *= 10;
        i += n % 10;
        n /= 10;
    }
    return i;
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
    int i, ri, ans;

    ans = 0;
    for ( i = 1; i < N; ++i ) {
        ri = reverse( i );
        if ( hasOdd( i + ri ) && ( int )log10( i ) == ( int )log10( ri ) ) {
            ++ans;
        }
    }
    printf( "%d\n", ans );

    return 0;
}
