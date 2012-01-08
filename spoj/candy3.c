#include <stdio.h>

int main() {
    int sum, i, N, T;
    long long j;

    //freopen( "in.txt", "r", stdin );

    scanf( "%d", &T );
    while ( T-- ) {
        scanf( "%d", &N );
        for ( i = sum = 0; i < N; ++i, sum = ( sum + j ) % N ) {
            scanf( "%lld", &j );
        }

        if ( sum ) {
            puts( "NO" );
        }
        else {
            puts( "YES" );
        }
    }

    return 0;
}
