#include <cstdio>
#include <vector>
#include <list>
#include <set>

using namespace std;

typedef pair< short, int > ii;

int *dijkstra( vector< list< ii > > L, int source ) {
    int i, v, v2, d2, *D;
    set< ii > S;
    list< ii >::iterator it;

    D = ( int* )malloc( L.size() * sizeof( int ) );
    for ( i = 0; i < L.size(); i += 1 ) {
        D[ i ] = 987654321;
    }

    D[ source ] = 0;
    S.insert( ii( D[ source ], source ) );
    while ( !S.empty() ) {
        v = S.begin()->second;
        S.erase( S.begin() );

        for ( it = L[ v ].begin(); it != L[ v ].end(); ++it ) {
            d2 = it->first;
            v2 = it->second;

            if ( D[ v2 ] > d2 + D[ v ] ) {
                if ( D[ v2 ] != 987654321 ) {
                    S.erase( ii( D[ v2 ], v2 ) );
                }
                D[ v2 ] = d2 + D[ v ];
                S.insert( ii( D[ v2 ], v2 ) );
            }
        }
    }

    return D;
}

int main() {
    short V, K, s, t, v, u;
    int E, w, min, *front, *back;

    vector< list< ii > > L, L2;

    freopen( "newroad.in", "r", stdin );
    freopen( "newroad.out", "w", stdout );

    scanf( "%hd %d %hd %hd %hd", &V, &E, &K, &s, &t );
    L.resize( V + 1 );
    L2.resize( V + 1 );

    while ( E-- ) {
        scanf( "%hd %hd %d", &v, &u, &w );

        L[ v ].push_back( ii( w, u ) );
        L2[ u ].push_back( ii( w, v ) );
    }

    front = dijkstra( L, s );
    back = dijkstra( L2, t );

    min = front[ t ];
    while ( K-- ) {
        scanf( "%hd %hd %d", &v, &u, &w );

        if ( front[ v ] != 98765431 || back[ u ] != 987654321 ) {
            if ( min > front[ v ] + w + back[ u ] ) {
                min = front[ v ] + w + back[ u ];
            }
        }
    }

    printf( "%d\n", min );

    return 0;
}
