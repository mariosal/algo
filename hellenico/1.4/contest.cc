#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

typedef pair< int, int > ii;

int dijkstra( vector< list< ii > > L, int source ) {
  int i, v, v2, d2, *D;
  set< ii > S;
  list< ii >::iterator it;

  D = ( int* )malloc( L.size() * sizeof( int ) );
  for ( i = 0; i < L.size(); i += 1 ) {
    D[ i ] = -1;
  }

  D[ source ] = 0;
  S.insert( ii( -D[ source ], source ) );
  while ( !S.empty() ) {
    v = S.begin()->second;
    S.erase( S.begin() );

    for ( it = L[ v ].begin(); it != L[ v ].end(); ++it ) {
      d2 = it->first;
      v2 = it->second;

      if ( D[ v2 ] < d2 + D[ v ] ) {
        if ( D[ v2 ] != -1 ) {
          S.erase( ii( -D[ v2 ], v2 ) );
        }
        D[ v2 ] = d2 + D[ v ];
        S.insert( ii( -D[ v2 ], v2 ) );
      }
    }
  }

  return *max_element( &D[ 0 ], &D[ L.size() ] );
}

int main() {
  int V, E, v, u, w;

  vector< list< ii > > L;

  freopen( "contest.in", "r", stdin );
  freopen( "contest.out", "w", stdout );

  scanf( "%d", &V );
  L.resize( V + 1 );
  while ( V-- ) {
    scanf( "%d %d %d", &v, &u, &w );

    L[ v ].push_back( ii( w, u ) );
  }
  printf( "%d\n", dijkstra( L, 1 ) );

  return 0;
}
