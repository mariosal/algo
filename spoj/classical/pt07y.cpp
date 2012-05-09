#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <queue>

using namespace std;

bool bfs( vector< list< int > > L, int source ) {
    int i, frontier;
    list< int >::iterator it;
    set< int > coloured;
    queue< int > Q;

    coloured.insert( source );
    Q.push( source );
    while ( !Q.empty() ) {
        frontier = Q.front();
        Q.pop();

        for ( it = L[ frontier ].begin(); it != L[ frontier ].end(); ++it ) {
            if ( coloured.insert( *it ).second ) {
                Q.push( *it );
            }
        }
    }

    return coloured.size() == L.size() - 1;
}

int main() {
    int V, E, p, r, i;

    vector< list< int > > L;

    scanf( "%d %d", &V, &E );
    L.resize( V + 1 );
    for ( i = 0; i < E; i += 1 ) {
        scanf( "%d %d", &p, &r );

        L[ p ].push_back( r );
        L[ r ].push_back( p );
    }

    if ( E == V - 1 && bfs( L, 1 ) ) {
        puts( "YES" );
    }
    else {
        puts( "NO" );
    }

    return 0;
}
