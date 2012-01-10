#include <cstdio>
#include <vector>
#include <list>
#include <set>

using namespace std;

typedef pair< short, int > ii;

vector< int > dijkstra( vector< list< ii > > L, short source ) {
    short v, v2;
    int d, d2;

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

    return D;
}

int main() {
    short V, K, s, t, v, u;
    int E, w, min;

    vector< int > front;
    vector< int > back;
    vector< list< ii > > L;

    freopen( "newroad.in", "r", stdin );
    freopen( "newroad.out", "w", stdout );

    scanf( "%hd %d %hd %hd %hd", &V, &E, &K, &s, &t );
    L.resize( V + 1 );

    while ( E-- ) {
        scanf( "%hd %hd %d", &v, &u, &w );

        L[ v ].push_back( ii( u, w ) );
    }

    front = dijkstra( L, s );
    back = dijkstra( L, t );

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
