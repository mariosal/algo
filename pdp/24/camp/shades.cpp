#include <cstdio>
#include <list>
#include <vector>

using namespace std;

enum Color {
  WHITE, BLACK, GRAY
};

void dfs( list< int > *G, Color *node, int s, vector< bool > &vis ) {
  list< int >::iterator it;

  for ( it = G[ s ].begin(); it != G[ s ].end(); ++it ) {
    if ( !vis[ *it ] ) {
      vis[ *it ] = true;
      if ( node[ *it ] != BLACK ) {
        dfs( G, node, *it, vis );
      }
    }
  }
}

int main() {
  char color;
  int i, j, s, t, n, m;
  Color *node;
  list< int > *G1, *G2;
  vector< bool > fromWhite, fromBlack;

  scanf( "%d %d\n", &n, &m );
  node = new Color[ n ];
  G1 = new list< int >[ n ];
  G2 = new list< int >[ n ];
  fromWhite.resize( n );
  fromBlack.resize( n );

  for ( i = 0; i < n; ++i ) {
    scanf( "%c ", &color );
    node[ i ] = ( Color )( color - '0' );
  }
  for ( i = 0; i < m; ++i ) {
    scanf( "%d %d", &s, &t );
    --s;
    --t;
    G1[ s ].push_back( t );
    G2[ t ].push_back( s );
  }

  for ( i = 0; i < n; ++i ) {
    switch ( node[ i ] ) {
      case WHITE:
        fromWhite[ i ] = true;
        dfs( G1, node, i, fromWhite );
        break;
      case BLACK:
        fromBlack[ i ] = true;
        dfs( G2, node, i, fromBlack );
        break;
    }
  }

  for ( i = 0; i < n; ++i ) {
    printf( "%c%s", fromWhite[ i ] && fromBlack[ i ] ? '1' : '0', i == n - 1 ? "\n" : " " );
  }

  return 0;
}
