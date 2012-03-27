#include <stdio.h>
#include <stdlib.h>

typedef struct {
    short x, y;
} point;

int cross( point a, point b, point c ) {
    return ( int )( b.x - a.x ) * ( c.y - a.y ) - ( b.y - a.y ) * ( c.x - a.x );
}
char inTriangle( point a, point b, point c, point d ) {
    return ( long )cross( a, b, d ) * cross( b, c, d ) > 0 &&
           ( long )cross( b, c, d ) * cross( c, a, d ) > 0;
}

int main() {
    short ans, i;
    point a, b, c, zero;

    ans = 0;
    zero.x = 0;
    zero.y = 0;
    for ( i = 0; i < 1000; ++i ) {
        scanf( "%hd,%hd,", &a.x, &a.y );
        scanf( "%hd,%hd,", &b.x, &b.y );
        scanf( "%hd,%hd\n", &c.x, &c.y );

        if ( inTriangle( a, b, c, zero ) ) {
            ++ans;
        }
    }
    printf( "%d\n", ans );

    return 0;
}
