#include <cstdio>

int main() {
    int i, j, maxPos, maxLen, *a, *w, *bt, n;

    scanf( "%d", &n );
    a = new int[ n ];
    w = new int[ n ];
    bt = new int[ n ];

    for ( i = 0; i < n; ++i ) {
        scanf( "%d", &a[ i ] );
    }

    for ( i = 0; i < n; ++i ) {
        w[ i ] = 1;
        bt[ i ] = -1;
    }

    for ( i = 1; i < n; ++i ) {
        for ( j = 0; j < i; ++j ) {
            if ( a[ j ] < a[ i ] && w[ i ] < w[ j ] + 1 ) {
                w[ i ] = w[ j ] + 1;
                bt[ i ] = j;
            }
        }
    }

    maxPos = 0;
    maxLen = w[ 0 ];
    for ( i = 1; i < n; ++i ) {
        if ( maxLen < w[ i ] ) {
            maxPos = i;
            maxLen = w[ i ];
        }
    }

    printf( "%d\n", maxLen );
    for ( i = maxPos; i != -1; i = bt[ i ] ) {
        printf( "%d ", a[ i ] );
    }
    printf( "\n" );

    return 0;
}
