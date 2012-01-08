#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

typedef pair< int, int > ii;

int dijkstra( vector< list< ii > > L, int source ) {
    int v, d, v2, d2;

    vector< int > D( L.size(), -1 );
    set< ii > S;
    list< ii >::iterator it;

    D[ source ] = 0;
    S.insert( ii( source, -D[ source ] ) );
    while ( !S.empty() ) {
        v = S.begin()->first;
        d = -S.begin()->second;

        S.erase( S.begin() );

        for ( it = L[ v ].begin(); it != L[ v ].end(); ++it ) {
            v2 = it->first;
            d2 = it->second;

            if ( D[ v2 ] < D[ v ] + d2 ) {
                if ( D[ v2 ] != -1 ) {
                    S.erase( ii( v2, -D[ v2 ] ) );
                }
                D[ v2 ] = D[ v ] + d2;
                S.insert( ii( v2, -D[ v2 ] ) );
            }
        }
    }

    return *max_element( D.begin(), D.end() );
}

int main() {
    int V, E, p, r, w, i;

    vector< list< ii > > L;

    freopen( "contest.in", "r", stdin );
    freopen( "contest.out", "w", stdout );

    scanf( "%d", &V );
    L.resize( V + 1 );
    for ( i = 0; i < V - 1; i += 1 ) {
        scanf( "%d %d %d", &p, &r, &w );

        L[ p ].push_back( ii( r, w ) );
    }
    printf( "%d\n", dijkstra( L, 1 ) );

    return 0;
}
