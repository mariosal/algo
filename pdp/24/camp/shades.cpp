#include <cstdio>
#include <vector>
#include <list>

using namespace std;

typedef struct {
  char type;
  list< int > edges;
} Node;

vector< bool > lucky;
vector< bool > visited;
Node *G;

void dfs( int src ) {
  list< int >::iterator it;

  if ( visited[ src ] ) {
    return;
  }

  visited[ src ] = true;
  for ( it = G[ src ].edges.begin(); it != G[ src ].edges.end(); ++it ) {
    if ( !visited[ *it ] && G[ *it ].type != 1 ) {
      dfs( *it );
    }
    if ( lucky[ *it ] ) {
      lucky[ src ] = true;
    }
    if ( G[ *it ].type == 1 ) {
      lucky[ src ] = true;
      lucky[ *it ] = true;
    }
  }
}

int main() {
  short dummy;
  int i, s, t, V, E, cntAgr, *agr;

  freopen( "shades.in", "r", stdin );
  freopen( "shades.out", "w", stdout );

  scanf( "%d %d", &V, &E );
  G = new Node[ V ];
  agr = new int[ V ];
  lucky.resize( V );
  visited.resize( V );

  cntAgr = 0;
  for ( i = 0; i < V; ++i ) {
    scanf( "%hd", &dummy );
    G[ i ].type = dummy;
    if ( G[ i ].type == 0 ) {
      agr[ cntAgr++ ] = i;
    }
  }

  for ( i = 0; i < E; ++i ) {
    scanf( "%d %d", &s, &t );
    --s;
    --t;
    G[ s ].edges.push_back( t );
  }

  for ( i = 0; i < V; ++i ) {
    lucky[ i ] = false;
    visited[ i ] = false;
  }
  for ( i = 0; i < cntAgr; ++i ) {
    if ( !visited[ agr[ i ] ] ) {
      dfs( i );
    }
  }

  for ( i = 0; i < V; ++i ) {
    if ( i ) {
      printf( " " );
    }
    if ( lucky[ i ] ) {
      printf( "1" );
    }
    else {
      printf( "0" );
    }
  }
  printf( "\n" );

  return 0;
}
