#include <cstdio>
#include <algorithm>

using namespace std;

struct Edge {
  short src, trg;
  int w;
};
bool operator <( Edge a, Edge b ) {
  if ( a.w == b.w ) {
    if ( a.src == b.src ) {
      return a.trg < b.trg;
    }
    return a.src < b.src;
  }
  return a.w < b.w;
}

struct Disjoint {
  short parent, rank;
};
Disjoint *sets;
short find( short a ) {
  if ( sets[ a ].parent != a ) {
    sets[ a ].parent = find( sets[ a ].parent );
  }
  return sets[ a ].parent;
}
void unite( short a, short b ) {
  a = find( a );
  b = find( b );

  if ( sets[ a ].rank > sets[ b ].rank ) {
    sets[ b ].parent = a;
  }
  else {
    sets[ a ].parent = b;
    if ( sets[ a ].rank == sets[ b ].rank ) {
      ++sets[ b ].rank;
    }
  }
}

long long kruskal( Edge *E, int m ) {
  int i;
  long long sum;

  sum = 0;
  sort( E, E + m );
  for ( i = 0; i < m; ++i ) {
    if ( find( E[ i ].src ) != find( E[ i ].trg ) ) {
      sum += E[ i ].w;
      unite( E[ i ].src, E[ i ].trg );
    }
  }

  return sum;
}

int main() {
  short src, trg, n;
  int i, w, m;
  Edge *E;

  scanf( "%hd %d", &n, &m );

  sets = new Disjoint[ n ];
  for ( i = 0; i < n; ++i ) {
    sets[ i ] = ( Disjoint ) {
      i, 0
    };
  }

  E = new Edge[ m ];
  for ( i = 0; i < m; ++i ) {
    scanf( "%hd %hd %d", &src, &trg, &w );
    --src;
    --trg;

    E[ i ] = ( Edge ) {
      src, trg, w
    };
  }

  printf( "%lld\n", kruskal( E, m ) );

  return 0;
}
