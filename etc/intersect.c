#include <stdio.h>

typedef struct {
    int x;
    int y;
} point;

long long direction( point A, point B, point C ) {
    // Cross Product: ( C - A ) × ( B - A )
    return ( B.x - A.x ) * ( C.y - A.y ) - ( B.y - A.y ) * ( C.x - A.x );
}

char intersect( point A, point B, point C, point D ) {
    return direction( A, B, C ) * direction( A, B, D ) < 0 &&
           direction( C, D, A ) * direction( C, D, B ) < 0;
}

int main() {
    point A, B, C, D;

    A.x = 0;
    A.y = 0;
    B.x = 10;
    B.y = 10;

    C.x = 5;
    C.y = 0;
    D.x = 0;
    D.y = 6;

    printf( "%d\n", intersect( A, B, C, D ) );

    return 0;
}
