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

int *dijkstra( list< Edge > *G, int n, int src ) {
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
  bool ans;
  short w;
  unsigned short q;
  int i, n, m, src, trg, a, b, c, *d[ 3 ];
  list< Edge > *G;

  scanf( "%d %d", &n, &m );
  G = new list< Edge >[ n ];

  while ( m-- ) {
    scanf( "%d %d %hd", &src, &trg, &w );
    --src;
    --trg;

    G[ src ].push_back( ( Edge ) {
      trg, w
    } );
    G[ trg ].push_back( ( Edge ) {
      src, w
    } );
  }

  scanf( "%d %d %d %hu", &a, &b, &c, &q );
  --a;
  --b;
  --c;
  
  d[ 0 ] = dijkstra( G, n, a );
  d[ 1 ] = dijkstra( G, n, b );
  d[ 2 ] = dijkstra( G, n, c );

  while ( q-- ) {
    scanf( "%d", &trg );
    --trg;

    ans = true;
    for ( i = 0; i < n; ++i ) {
      if ( d[ 0 ][ trg ] > d[ 0 ][ i ] && d[ 1 ][ trg ] > d[ 1 ][ i ] && d[ 2 ][ trg ] > d[ 2 ][ i ] ) {
        ans = false;
        break;
      }
    }
    printf( "%s\n", ans ? "YES" : "NO" );
  }

  return 0;
}
