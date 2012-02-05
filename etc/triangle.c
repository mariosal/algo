#include <stdio.h>

typedef struct {
    int x;
    int y;
} point;

long long direction( point A, point B, point C ) {
    // Cross Product: ( C - A ) × ( B - A )
    return ( long long )( B.x - A.x ) * ( C.y - A.y ) - ( B.y - A.y ) * ( C.x - A.x );
}

char inTriangle( point A, point B, point C, point D ) {
    return direction( A, B, D ) * direction( B, C, D ) > 0 &&
           direction( B, C, D ) * direction( C, A, D ) > 0;
}

int main() {
    point A, B, C, D;

    A.x = 0;
    A.y = 0;
    B.x = 0;
    B.y = 10;
    C.x = 5;
    C.y = 0;

    D.x = 2;
    D.y = 5;

    printf( "%d\n", inTriangle( A, B, C, D ) );

    return 0;
}
