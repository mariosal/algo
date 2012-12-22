#include <cstdio>
#include <climits>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

void dijkstra( list< pair< int, short > > *G, short src, int *w ) {
  pair< int, short > e;
  set< pair< int, short > > s;
  list< pair< int, short > >::iterator it;

  w[ src ] = 0;
  s.insert( make_pair( w[ src ], src ) );
  while ( !s.empty() ) {
    e = *s.begin();
    s.erase( s.begin() );

    for ( it = G[ e.second ].begin(); it != G[ e.second ].end(); ++it ) {
      if ( w[ it->second ] > e.first + it->first ) {
        if ( w[ it->second ] != 987654321 ) {
          s.erase( make_pair( w[ it->second ], it->second ) );
        }
        w[ it->second ] = e.first + it->first;
        s.insert( make_pair( w[ it->second ], it->second ) );
      }
    }
  }
}

int main() {
  short i, src, trg, n, t, u, v, k;
  int m, w, best, *fwd, *rwd;
  list< pair< int, short > > *F, *R;

  fwd = new int[ 10000 ];
  rwd = new int[ 10000 ];
  F = new list< pair< int, short > >[ 10000 ];
  R = new list< pair< int, short > >[ 10000 ];

  scanf( "%hd", &t );
  while ( t-- ) {
    scanf( "%hd %d %hd %hd %hd", &n, &m, &k, &src, &trg );
    --src;
    --trg;

    for ( i = 0; i < n; ++i ) {
      fwd[ i ] = rwd[ i ] = 987654321;
      F[ i ].clear();
      R[ i ].clear();
    }

    while ( m-- ) {
      scanf( "%hd %hd %d", &u, &v, &w );
      --u;
      --v;

      F[ u ].push_back( make_pair( w, v ) );
      R[ v ].push_back( make_pair( w, u ) );
    }

    dijkstra( F, src, fwd );
    dijkstra( R, trg, rwd );

    best = fwd[ trg ];
    while ( k-- ) {
      scanf( "%hd %hd %d", &u, &v, &w );
      --u;
      --v;

      best = min( best, min( fwd[ u ] + w + rwd[ v ], fwd[ v ] + w + rwd[ u ] ) );
    }
    if ( best == 987654321 ) {
      printf( "-1\n" );
    }
    else {
      printf( "%d\n", best );
    }
  }

  return 0;
}
