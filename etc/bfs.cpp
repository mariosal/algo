#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <queue>

using namespace std;

bool bfs( vector< list< int > > L, int source, int target ) {
    int frontier;
    list< int >::iterator it;
    set< int > coloured;
    queue< int > Q;

    coloured.insert( source );
    Q.push( source );
    while ( !Q.empty() ) {
        frontier = Q.front();
        Q.pop();

        for ( it = L[ frontier ].begin(); it != L[ frontier ].end(); ++it ) {
            if ( *it == target ) {
                return true;
            }
            if ( coloured.insert( *it ).second ) {
                Q.push( *it );
            }
        }
    }

    return false;
}

int main() {
    int V, E, p, r, i;

    vector< list< int > > L;

    freopen( "graph.in", "r", stdin );
    freopen( "bfs.out", "w", stdout );

    scanf( "%d %d", &V, &E );
    L.resize( V + 1 );
    for ( i = 0; i < E; i += 1 ) {
        scanf( "%d %d %*d", &p, &r );

        L[ p ].push_back( r );
    }
    printf( "%d\n", bfs( L, 1, 5 ) );

    fclose( stdin );
    fclose( stdout );

    return 0;
}
