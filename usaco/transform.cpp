/*
    ID: mariosa1
    LANG: C++
    TASK: transform
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct {
    short n;
    char **b;
} Board;

void aloc( Board *a ) {
    char i;

    a->b = ( char** )malloc( a->n * sizeof( char* ) );
    for ( i = 0; i < a->n; i += 1 ) {
        a->b[ i ] = ( char* )malloc( a->n );
    }
}
void read( Board *a ) {
    char i;
    for ( i = 0; i < a->n; i += 1 ) {
        scanf( "%s", a->b[ i ] );
    }
}

Board rotate( Board a ) {
    char i, j;
    Board b;

    b.n = a.n;
    aloc( &b );
    for ( i = 0; i < a.n; i += 1 ) {
        for ( j = 0; j < a.n; j += 1 ) {
            b.b[ j ][ a.n - i - 1 ] = a.b[ i ][ j ];
        }
    }
    return b;
}
Board reflect( Board a ) {
    char i, j;
    Board b;

    b.n = a.n;
    aloc( &b );
    for ( i = 0; i < a.n; i += 1 ) {
        for ( j = 0; j < a.n; j += 1 ) {
            b.b[ i ][ a.n - j - 1 ] = a.b[ i ][ j ];
        }
    }
    return b;
}

bool operator == ( Board a, Board b ) {
    char i;
    for ( i = 0; i < a.n; i += 1 ) {
        if ( strcmp( a.b[ i ], b.b[ i ] ) ) {
            return false;
        }
    }
    return true;
}

int main() {
    char i, change;
    Board a, b;

    freopen( "transform.in", "r", stdin );
    freopen( "transform.out", "w", stdout );

    scanf( "%hd", &a.n );
    b.n = a.n;

    aloc( &a );
    aloc( &b );

    read( &a );
    read( &b );

    if ( rotate( a ) == b ) {
        change = 1;
    }
    else if ( rotate( rotate( a ) ) == b ) {
        change = 2;
    }
    else if ( rotate( rotate( rotate( a ) ) ) == b ) {
        change = 3;
    }
    else if ( reflect( a ) == b ) {
        change = 4;
    }
    else if ( reflect( rotate( a ) ) == b ||
              reflect( rotate( rotate( a ) ) ) == b ||
              reflect( rotate( rotate( rotate( a ) ) ) ) == b ) {
        change = 5;
    }
    else if ( a == b ) {
        change = 6;
    }
    else {
        change = 7;
    }

    printf( "%d\n", change );

    return 0;
}
