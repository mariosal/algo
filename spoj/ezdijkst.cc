#include <cstdio>
#include <climits>
#include <set>
#include <list>

using namespace std;

struct Edge {
  short trg, w;
};
bool operator <( Edge a, Edge b ) {
  if ( a.w == b.w ) {
    return a.trg < b.trg;
  }
  return a.w < b.w;
}

int *dijkstra( list< Edge > *G, short n, short src ) {
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

  return w;
}

int main() {
  short src, trg, w, n, m, t;
  int cost;
  list< Edge > *G;

  scanf( "%hd", &t );
  while ( t-- ) {
    scanf( "%hd %hd", &n, &m );
    G = new list< Edge >[ n ];

    while ( m-- ) {
      scanf( "%hd %hd %hd", &src, &trg, &w );
      --src;
      --trg;

      G[ src ].push_back( ( Edge ) {
        trg, w
      } );
    }

    scanf( "%hd %hd", &src, &trg );
    --src;
    --trg;

    cost = dijkstra( G, n, src )[ trg ];
    if ( cost == INT_MAX ) {
      printf( "NO\n" );
    }
    else {
      printf( "%d\n", cost );
    }
  }

  return 0;
}
