/*
    ID: mariosa1
    LANG: C
    TASK: friday
*/
#include <stdio.h>

char isLeap( short year ) {
    return year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0);
}

char len( short year, short month ) {
    char months[ 12 ] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ( month == 1 ) {
        return months[ month ] + isLeap( year );
    }
    return months[ month ];
}

int main() {
    char j, q;
    short N, i, days[ 7 ];

    freopen( "friday.in", "r", stdin );
    freopen( "friday.out", "w", stdout );

    scanf( "%hd", &N );
    for ( i = 0; i < 7; i += 1 ) {
        days[ i ] = 0;
    }

    q = 0;
    for ( i = 1900; i < 1900 + N; i += 1 ) {
        for ( j = 0; j < 12; j += 1 ) {
            days[ q ] += 1;
            q = ( q + len( i, j ) ) % 7;
        }
    }

    for ( i = 0; i < 7; i += 1 ) {
        if ( i ) {
            putchar( ' ' );
        }
        printf( "%hd", days[ i ] );
    }
    putchar( '\n' );

    fclose( stdin );
    fclose( stdout );

    return 0;
}
