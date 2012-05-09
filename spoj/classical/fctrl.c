#include <math.h>
#include <stdio.h>

int N, i;

int Z( int N ) {
    int i = 0, j;

    for ( j = 5; j <= N; j *= 5 ) {
        i += N / j;
    }
    return i;
}

int main() {
    scanf( "%d", &N );
    while ( N-- ) {
        scanf( "%d", &i );
        printf( "%d\n", Z( i ) );
    }

    return 0;
}
