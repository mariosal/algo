/*
    PROG: barn1
    ID: mariosa1
    LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
int asc( const void *a, const void *b ) {
    return *( short* )a - *( short* )b;
}
int desc( const void *a, const void *b ) {
    return *( short* )b - *( short* )a;
}
int main() {
    short i, j, q, length, *barns, *gaps, M, S, C;
    freopen( "barn1.in", "r", stdin );
    freopen( "barn1.out", "w", stdout );
    scanf( "%hd %hd %hd", &M, &S, &C );
    barns = ( short* )malloc( sizeof( short ) * C );
    gaps = ( short* )malloc( sizeof( short ) * ( C - 1 ) );
    for ( i = 0; i < C; ++i ) {
        scanf( "%hd", &barns[ i ] );
    }
    qsort( barns, C, sizeof( short ), &asc );
    for ( i = 0; i < C - 1; ++i ) {
        gaps[ i ] = barns[ i + 1 ] - barns[ i ] - 1;
    }
    qsort( gaps, C - 1, sizeof( short ), &desc );
    if ( C <= M ) {
        length = C;
    }
    else {
        length = barns[ C - 1 ] - barns[ 0 ] + 1;
        for ( i = 0; i < M - 1; ++i ) {
            length -= gaps[ i ];
        }
    }
    printf( "%hd\n", length );
    return 0;
}
