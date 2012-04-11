#include <cstdio>
#include <cstdlib>
#include <list>
#include <set>
#include <map>
#include <string>

using namespace std;

#define ii pair< long long, int >

typedef struct {
    int target;
    long long weight;
} node;

long long *dijkstra( list< node > *L, int V, int source ) {
    int i, front;
    long long *D;
    set< ii > s;
    list< node >::iterator it;

    D = ( long long* )malloc( V * sizeof( long long ) );
    for ( i = 0; i < V; ++i ) {
        D[ i ] = 987654321;
    }

    D[ source ] = 0;
    s.insert( ii( D[ source ], source ) );
    while ( !s.empty() ) {
        front = s.begin()->second;
        s.erase( s.begin() );

        for ( it = L[ front ].begin(); it != L[ front ].end(); ++it ) {
            if ( D[ it->target ] > it->weight + D[ front ] ) {
                if ( D[ it->target ] != 987654321 ) {
                    s.erase( ii( D[ it->target ], it->target ) );
                }
                D[ it->target ] = it->weight + D[ front ];
                s.insert( ii( D[ it->target ], it->target ) );
            }
        }
    }

    return D;
}

int main() {
    char source[ 11 ], target[ 11 ];
    int t, i, V, E;
    node dummy;
    map< string, int > m;
    list< node > *L;

    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d", &V );
        L = new list< node >[ V ];

        for ( i = 0; i < V; ++i ) {
            scanf( "%s", source );
            m[ source ] = i;

            scanf( "%d", &E );
            while ( E-- ) {
                scanf( "%d %lld", &dummy.target, &dummy.weight );
                --dummy.target;

                L[ i ].push_back( dummy );
            }
        }

        scanf( "%d", &E );
        while ( E-- ) {
            scanf( "%s %s", source, target );
            printf( "%lld\n", dijkstra( L, V, m[ source ] )[ m[ target ] ] );
        }

        m.clear();
        delete[] L;
    }

    return 0;
}
