#include <cstdio>
#include <cstdlib>
#include <list>
#include <set>

using namespace std;

#define ii pair< int, int >

typedef struct {
    int target;
    int weight;
} node;

int *dijkstra( list< node > *L, int V, int source ) {
    int i, front, *D;
    set< ii > s;
    list< node >::iterator it;

    D = ( int* )malloc( V * sizeof( int ) );
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
    int t, V, E, source, target, *D;
    node dummy;
    list< node > *L;

    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d %d", &V, &E );
        L = new list< node >[ V ];

        while ( E-- ) {
            scanf( "%d %d %d", &source, &dummy.target, &dummy.weight );
            --source;
            --dummy.target;

            L[ source ].push_back( dummy );
        }

        scanf( "%d %d", &source, &target );
        --source;
        --target;
        D = dijkstra( L, V, source );
        if ( D[ target ] == 987654321 ) {
            printf( "NO\n" );
        }
        else {
            printf( "%d\n", D[ target ] );
        }

        delete[] L;
    }

    return 0;
}
