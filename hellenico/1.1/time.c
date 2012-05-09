#include <stdio.h>

int main() {
    short h, m, s;

    freopen( "time.in", "r", stdin );
    freopen( "time.out", "w", stdout );
    
    scanf( "%hd:%hd:%hd", &h, &m, &s );
    
    s *= 2;
    m *= 2;
    h *= 2;
    
    if ( s > 59 ) {
        m += 1;
        s -= 60;
    }
    if ( m > 59 ) {
        h += 1;
        m -= 60;
    }

    printf( "%02hd:%02hd:%02hd\n", h, m, s );

    return 0;
}
