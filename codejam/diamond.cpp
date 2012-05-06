#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <set>

using namespace std;

bool dfs( short **E, short source ) {
    short i, top;
    set< short > mark;
    stack< short > s;

    s.push( source );
    mark.insert( source );
    while ( !s.empty() ) {
        top = s.top();
        s.pop();

        for ( i = 1; i <= E[ top ][ 0 ]; ++i ) {
            if ( !mark.insert( E[ top ][ i ] ).second ) {
                return true;
            }
            else {
                s.push( E[ top ][ i ] );
            }
        }
    }
    return false;
}

int main() {
    char ans[ 4 ];
    short i, j, q, t, cntV, neighbors, **E;

    scanf( "%hd", &t );
    for ( i = 1; i <= t; ++i ) {
        scanf( "%hd", &cntV );
        E = ( short** )malloc( cntV * sizeof( short* ) );

        for ( j = 0; j < cntV; ++j ) {
            scanf( "%hd", &neighbors );
            E[ j ] = ( short* )malloc( ( neighbors + 1 ) * sizeof( short ) );

            E[ j ][ 0 ] = neighbors;
            for ( q = 1; q <= E[ j ][ 0 ]; ++q ) {
                scanf( "%hd", &E[ j ][ q ] );
                --E[ j ][ q ];
            }
        }

        strcpy( ans, "No" );
        for ( j = 0; j < cntV; ++j ) {
            if ( dfs( E, j ) ) {
                strcpy( ans, "Yes" );
                break;
            }
        }

        printf( "Case #%d: %s\n", i, ans );
    }

    return 0;
}
