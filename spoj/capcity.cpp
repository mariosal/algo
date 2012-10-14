#include <cstdio>
#include <vector>
#include <set>
#include <list>

using namespace std;

void dfs( list< int > *G, int s, vector< bool > &vis, list< int > &l ) {
  if ( !vis[ s ] ) {
    vis[ s ] = true;
    for ( list< int >::iterator it = G[ s ].begin(); it != G[ s ].end(); ++it ) {
      dfs( G, *it, vis, l );
    }
    l.push_back( s );
  }
}

int main() {
  int i, n, m, s, t;
  vector< bool > vis;
  list< int > l, *G;
  list< int >::iterator it;

  scanf( "%d %d", &n, &m );
  G = new list< int >[ n ];
  vis.resize( n );

  for ( i = 0; i < m; ++i ) {
    scanf( "%d %d", &s, &t );
    --s;
    --t;
    G[ s ].push_back( t );
  }

  for ( i = 0; i < n; ++i ) {
    dfs( G, i, vis, l );
  }

  for ( i = 0; i < n; ++i ) {
    vis[ i ] = false;
  }
  s = *l.begin();
  l.clear();
  dfs( G, s, vis, l );

  l.sort();
  printf( "%zd\n", l.size() );
  for ( it = l.begin(); it != l.end(); ++it ) {
    printf( "%s%d", it == l.begin() ? "" : " ", *it + 1 );
  }
  printf( "\n" );

  return 0;
}
