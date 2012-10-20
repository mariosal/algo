#include <cstdio>
#include <cstring>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

enum Value {
  FALSE, TRUE, UNKNOWN
};
struct Edge {
  char t;
  Value w;
};

vector< char > T;
list< Edge > *G;

void topo( char s, vector< bool > &vis ) {
  list< Edge >::iterator it;

  if ( !vis[ s ] ) {
    vis[ s ] = true;
    for ( it = G[ s ].begin(); it != G[ s ].end(); ++it ) {
      topo( it->t, vis );
    }
    T.push_back( s );
  }
}
bool dfs( char s, Value w, Value *vis ) {
  Value nW;
  list< Edge >::iterator it;

  if ( vis[ s ] == UNKNOWN ) {
    vis[ s ] = w;
    for ( it = G[ s ].begin(); it != G[ s ].end(); ++it ) {
      if ( vis[ s ] == FALSE ) {
        nW = it->w == TRUE ? FALSE : TRUE;
      }
      else {
        nW = it->w;
      }
      if ( !dfs( it->t, nW, vis ) ) {
        return false;
      }
    }
  }
  else if ( vis[ s ] != w ) {
    return false;
  }
  return true;
}

int main() {
  bool ans;
  char w[ 6 ];
  short i, j, n, t;
  Value *v1;
  Value *v2;
  vector< bool > vis;

  while ( 1 ) {
    scanf( "%hd", &n );
    if ( !n ) {
      break;
    }

    vis.resize( n );
    T.resize( n );
    v1 = new Value[ n ];
    v2 = new Value[ n ];
    G = new list< Edge >[ n ];

    for ( i = 0; i < n; ++i ) {
      scanf( "%hd %s", &t, &w );
      --t;

      vis[ i ] = false;
      G[ i ].push_back( ( Edge ) {
        t, !strcmp( w, "true" ) ? TRUE : FALSE
      } );
    }

    for ( i = 0; i < n; ++i ) {
      topo( i, vis );
    }
    reverse( T.begin(), T.end() );

    ans = true;
    for ( i = n - 1; i >= 0; --i ) {
      for ( j = 0; j < n; ++j ) {
        v1[ j ] = UNKNOWN;
        v2[ j ] = UNKNOWN;
      }

      if ( !dfs( T[ i ], TRUE, v1 ) ) {
        ans = false;
      }
      if ( !ans && !dfs( T[ i ], FALSE, v2 ) ) {
        ans = false;
      }
    }

    if ( ans ) {
      printf( "NOT PARADOX\n" );
    }
    else {
      printf( "PARADOX\n" );
    }

    T.clear();
    delete[] v1;
    delete[] v2;
    delete[] G;
  }

  return 0;
}
