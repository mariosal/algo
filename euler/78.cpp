#include <cstdio>

int main() {
    int i, j, *w;
    const int N = 56000;

    w = new int[ N + 1 ];
    for ( i = 0; i <= N; ++i ) {
        w[ i ] = 0;
    }
    
    w[ 0 ] = 1;
    for ( i = 1; i < N; ++i ) {
        for ( j = i; j <= N; ++j ) {
            w[ j ] = ( w[ j ] + w[ j - i ] ) % 1000000;
        }
    }
    for ( i = 0; i <= N; ++i ) {
        if ( w[ i ] == 0 ) {
            printf( "%d\n", i );
        }
    }

    return 0;
}
