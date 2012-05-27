#include <cstdio>

int main() {
    char i, prime[ 7 ] = { 2, 3, 5, 7, 11, 13, 17 };
    int ans;

    ans = 1;
    for ( i = 0; i < 7; ++i ) {
        ans *= prime[ i ];
    }
    printf( "%d\n", ans );

    return 0;
}
