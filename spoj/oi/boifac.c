#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int facLen( int n ) {
    int i;
    double facLog;

    facLog = 1;
    for ( i = 2; i <= n; i += 1 ) {
        facLog += log10( i );
    }

    return floor( facLog );
}

int main() {
    int n, i, times, fac, *a;

    scanf( "%d", &n );
    times = 0;
    a = NULL;
    for ( i = 1, fac = 1; fac <= n; i += 1, fac = facLen( i ) ) {
        if ( fac == n ) {
            a = ( int* )realloc( a, ( times + 1 ) * sizeof( int ) );
            a[ times ] = i;
            times += 1;
        }
    }

    if ( !times ) {
        puts( "NO" );
    }
    else {
        printf( "%d\n", times );
        for ( i = 0; i < times; i += 1 ) {
            printf( "%d\n", a[ i ] );
        }
    }

    return 0;
}
