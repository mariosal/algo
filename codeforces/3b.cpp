#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct {
    short value;
    char size;
} Node;

int main() {
    int n, maxSize, i, j;
    int **w;
    Node *item;

    scanf( "%d %d", &n, &maxSize );

    item = new Node[ n ];
    w = new int*[ n + 1 ];
    for ( i = 0; i <= n; ++i ) {
        w[ i ] = new int[ maxSize + 1 ];
        w[ i ][ 0 ] = 0;
    }
    for ( i = 0; i <= maxSize; ++i ) {
        w[ 0 ][ i ] = 0;
    }

    for ( i = 0; i < n; ++i ) {
        scanf( "%d %hd", &j, &item[ i ].value );
        item[ i ].size = j;
    }

    for ( i = 1; i <= maxSize; ++i ) {
        for ( j = 1; j <= n; ++j ) {
            w[ j ][ i ] = w[ j - 1 ][ i ];
            if ( item[ j - 1 ].size <= i ) {
                w[ j ][ i ] = max( w[ j ][ i ], w[ j - 1 ][ i - item[ j - 1 ].size ] + item[ j - 1 ].value );
            }
        }
    }

    printf( "%d\n", w[ n ][ maxSize ] );
    for ( i = n; i >= 1; --i ) {
        if ( w[ i ][ maxSize ] != w[ i - 1 ][ maxSize ] ) {
            printf( "%d ", i );
            maxSize -= item[ i - 1 ].size;
        }
    }
    printf( "\n" );

    return 0;
}
