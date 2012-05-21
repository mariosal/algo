#include <cstdio>
#include <cstdlib>

int main() {
    short coins[ 8 ] = { 1, 2, 5, 10, 20, 50, 100, 200 };
    int i, j, w[ 201 ];

    for ( i = 0; i <= 200; ++i ) {
        w[ i ] = 0;
    }
    
    w[ 0 ] = 1;
    for ( i = 0; i < 8; ++i ) {
        for ( j = coins[ i ]; j <= 200; ++j ) {
            w[ j ] += w[ j - coins[ i ] ];
        }
    }
    printf( "%d\n", w[ 200 ] );

    return 0;
}
