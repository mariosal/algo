#include <cstdio>
#include <list>
#include <set>

using namespace std;

struct Edge {
  short trg;
  int w;
};
bool operator <( Edge a, Edge b ) {
  if ( a.w == b.w ) {
    return a.trg < b.trg;
  }
  return a.w < b.w;
}

long long prim( list< Edge > *G ) {
  long long sum;
  Edge e;
  set< short > mark;
  set< Edge > s;
  list< Edge >::iterator it;

  sum = 0;
  s.insert( ( Edge ) {
    0, 0
  } );
  while ( !s.empty() ) {
    e = *s.begin();
    s.erase( s.begin() );

    if ( mark.insert( e.trg ).second ) {
      sum += e.w;
      for ( it = G[ e.trg ].begin(); it != G[ e.trg ].end(); ++it ) {
        s.insert( *it );
      }
    }
  }

  return sum;
}

int main() {
  short src, trg, V;
  int w, E;
  list< Edge > *G;

  scanf( "%hd %d", &V, &E );
  G = new list< Edge >[ V ];

  while ( E-- ) {
    scanf( "%hd %hd %d", &src, &trg, &w );
    --src;
    --trg;

    G[ src ].push_back( ( Edge ) {
      trg, w
    } );
    G[ trg ].push_back( ( Edge ) {
      src, w
    } );
  }

  printf( "%lld\n", prim( G ) );

  return 0;
}
