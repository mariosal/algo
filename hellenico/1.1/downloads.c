#include <stdio.h>

int main() {
    short N;
    int kb, k, t;
    float time;

    freopen( "downloads.in", "r", stdin );
    freopen( "downloads.out", "w", stdout );

    scanf( "%hd", &N );

    while ( N-- ) {
        scanf( "%d %d", &k, &t );

        kb += k;
        time += ( t - time ) * k / kb;
    }

    printf( "%.0f\n", time );

    return 0;
}

