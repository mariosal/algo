#include <cstdio>
#include <climits>
#include <set>
#include <list>

using namespace std;

struct Edge {
  int trg, w;
};
bool operator <( Edge a, Edge b ) {
  if ( a.w == b.w ) {
    return a.trg < b.trg;
  }
  return a.w < b.w;
}

int dijkstra( list< Edge > *G, int n, int src, int trg ) {
  int *w;
  Edge e;
  set< Edge > s;
  list< Edge >::iterator it;

  w = new int[ n ];
  while ( n-- ) {
    w[ n ] = INT_MAX;
  }

  w[ src ] = 0;
  s.insert( ( Edge ) {
    src, w[ src ]
  } );
  while ( !s.empty() ) {
    e = *s.begin();
    s.erase( s.begin() );

    if ( e.trg == trg ) {
      return e.w;
    }

    for ( it = G[ e.trg ].begin(); it != G[ e.trg ].end(); ++it ) {
      if ( w[ it->trg ] > e.w + it->w ) {
        if ( w[ it->trg ] != INT_MAX ) {
          s.erase( ( Edge ) {
            it->trg, w[ it->trg ]
          } );
        }
        w[ it->trg ] = e.w + it->w;
        s.insert( ( Edge ) {
          it->trg, w[ it->trg ]
        } );
      }
    }
  }
  return INT_MAX;
}

int main() {
  int cost, u, v, src, trg, w, n, m, t;
  list< Edge > *G;

  scanf( "%d", &t );
  while ( t-- ) {
    scanf( "%d %d %d %d", &n, &m, &src, &trg );
    --src;
    --trg;
    G = new list< Edge >[ n ];

    while ( m-- ) {
      scanf( "%d %d %d", &u, &v, &w );
      --u;
      --v;

      G[ u ].push_back( ( Edge ) {
        v, w
      } );
      G[ v ].push_back( ( Edge ) {
        u, w
      } );
    }

    cost = dijkstra( G, n, src, trg );
    if ( cost == INT_MAX ) {
      printf( "NONE\n" );
    }
    else {
      printf( "%d\n", cost );
    }
  }

  return 0;
}
