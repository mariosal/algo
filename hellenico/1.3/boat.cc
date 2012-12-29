#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int i, N, in, o;
  char car[ 43 ];
  vector< string > V;

  freopen( "boat.in", "r", stdin );
  freopen( "boat.out", "w", stdout );

  scanf( "%d", &N );

  while ( N-- ) {
    scanf( "%d %d", &o, &in );

    while ( o-- ) {
      V.erase( V.end() );
    }

    while ( in-- ) {
      scanf( "%s", &car );
      V.push_back( car );
    }
  }

  sort( V.begin(), V.end() );

  for ( i = 0; i < V.size(); i += 1 ) {
    printf( "%s\n", V[ i ].c_str() );
  }

  return 0;
}
