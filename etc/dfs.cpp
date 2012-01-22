#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <stack>

using namespace std;

bool dfs( vector< list< int > > L, int source, int target ) {
    int frontier;
    list< int >::iterator it;
    set< int > coloured;
    stack< int > S;

    coloured.insert( source );
    S.push( source );
    while ( !S.empty() ) {
        frontier = S.top();
        S.pop();

        for ( it = L[ frontier ].begin(); it != L[ frontier ].end(); ++it ) {
            if ( *it == target ) {
                return true;
            }
            if ( coloured.insert( *it ).second ) {
                S.push( *it );
            }
        }
    }

    return false;
}

int main() {
    int V, E, p, r, i;

    vector< list< int > > L;

    freopen( "graph.in", "r", stdin );

    scanf( "%d %d", &V, &E );
    L.resize( V + 1 );
    for ( i = 0; i < E; i += 1 ) {
        scanf( "%d %d %*d", &p, &r );

        L[ p ].push_back( r );
    }
    printf( "%d\n", dfs( L, 1, 5 ) );

    return 0;
}
