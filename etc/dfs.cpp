#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <stack>

using namespace std;

bool dfs( vector< list< int > > L, int source, int target ) {
    int frontier;
    list< int >::iterator it;
    set< int > S;
    stack< int > St;

    St.push( source );
    while ( !St.empty() ) {
        frontier = St.top();
        St.pop();
        S.insert( frontier );

        for ( it = L[ frontier ].begin(); it != L[ frontier ].end(); ++it ) {
            if ( *it == target ) {
                return true;
            }
            if ( S.insert( *it ).second ) {
                St.push( *it );
            }
        }
    }

    return false;
}

int main() {
    int V, E, p, r, i;

    vector< list< int > > L;

    freopen( "graph.in", "r", stdin );
    freopen( "dfs.out", "w", stdout );

    scanf( "%d %d", &V, &E );
    L.resize( V + 1 );
    for ( i = 0; i < E; ++i ) {
        scanf( "%d %d %*d", &p, &r );

        L[ p ].push_back( r );
    }
    printf( "%d\n", dfs( L, 1, 5 ) );

    fclose( stdin );
    fclose( stdout );

    return 0;
}
