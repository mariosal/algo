#include <cstdio>
#include <vector>
#include <list>
#include <set>

using namespace std;

typedef pair< int, int > ii;

int dijkstra( vector< list< ii > > L, int source, int target ) {
    int v, d, v2, d2;

    vector< int > D( L.size(), 987654321 );
    set< ii > S;
    list< ii >::iterator it;

    D[ source ] = 0;
    S.insert( ii( source, D[ source ] ) );
    while ( !S.empty() ) {
        v = S.begin()->first;
        d = S.begin()->second;

        S.erase( S.begin() );

        for ( it = L[ v ].begin(); it != L[ v ].end(); ++it ) {
            v2 = it->first;
            d2 = it->second;

            if ( D[ v2 ] > D[ v ] + d2 ) {
                if ( D[ v2 ] != 987654321 ) {
                    S.erase( ii( v2, D[ v2 ] ) );
                }
                D[ v2 ] = D[ v ] + d2;
                S.insert( ii( v2, D[ v2 ] ) );
            }
        }
    }

    return D[ target ];
}

int main() {
    int V, E, p, r, w, i;

    vector< list< ii > > L;

    freopen( "graph.in", "r", stdin );
    freopen( "dijkstra.out", "w", stdout );

    scanf( "%d %d", &V, &E );
    L.resize( V + 1 );
    for ( i = 0; i < E; i += 1 ) {
        scanf( "%d %d %d", &p, &r, &w );

        L[ p ].push_back( ii( r, w ) );
        L[ r ].push_back( ii( p, w ) );
    }
    printf( "%d\n", dijkstra( L, 1, 5 ) );

    fclose( stdin );
    fclose( stdout );

    return 0;
}
