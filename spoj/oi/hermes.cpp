#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>

using namespace std;

typedef struct {
    short n;
    int x, y, d;
} state;

int bf( short **p, short n ) {
    int min;
    state cur, next;
    queue< state > Q;

    min = 987654321;

    cur.n = -1;
    cur.x = 0;
    cur.y = 0;
    cur.d = 0;
    Q.push( cur );

    while ( !Q.empty() ) {
        cur = Q.front();
        Q.pop();

        if ( cur.n + 1 < n ) {
            next.n = cur.n + 1;

            next.x = p[ next.n ][ 0 ];
            next.y = cur.y;
            next.d = cur.d + abs( cur.x - next.x );
            Q.push( next );

            next.x = cur.x;
            next.y = p[ next.n ][ 1 ];
            next.d = cur.d + abs( cur.y - next.y );
            Q.push( next );
        }
        else if ( min > cur.d ) {
            min = cur.d;
        }
    }

    return min;
}

int main() {
    short n, i, **p;

    scanf( "%hd", &n );
    p = ( short** )malloc( n * sizeof( short* ) );

    for ( i = 0; i < n; i += 1 ) {
        p[ i ] = ( short* )malloc( 2 * sizeof( short ) );

        scanf( "%hd %hd", &p[ i ][ 0 ], &p[ i ][ 1 ] );
    }

    printf( "%d\n", bf( p, n ) );

    return 0;
}
