/*
    ID: mariosa1
    LANG: C
    TASK: ride
*/
#include <stdio.h>
#include <string.h>

char hash( char *s ) {
    char i, sum;
    for ( i = 0, sum = 1; s[ i ]; i += 1 ) {
        sum = ( sum * ( s[ i ] - 'A' + 1 ) ) % 47;
    }
    return sum;
}

int main() {
    char comet[ 7 ], group[ 7 ];

    freopen( "ride.in", "r", stdin );
    freopen( "ride.out", "w", stdout );

    scanf( "%s\n%s", comet, group );

    if ( hash( comet ) == hash( group ) ) {
        puts( "GO" );
    }
    else {
        puts( "STAY" );
    }

    return 0;
}
