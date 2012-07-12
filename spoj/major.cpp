#include <cstdio>
#include <map>

using namespace std;

int main() {
  short t, i, j, max[ 2 ];
  int n;
  map< short, int > M;
  map< short, int >::iterator it;

  //freopen( "in.txt", "r", stdin );

  scanf( "%hd", &t );
  while ( t-- ) {
    scanf( "%d", &n );
    for ( j = 0; j < n; ++j ) {
      scanf( "%hd", &i );

      ++M[ i ];
    }

    max[ 0 ] = M.begin()->first;
    max[ 1 ] = M.begin()->second;
    for ( it = M.begin(); it != M.end(); ++it ) {
      if ( max[ 1 ] < it->second ) {
        max[ 0 ] = it->first;
        max[ 1 ] = it->second;
      }
      it->second = 0;
    }

    if ( max[ 1 ] > n / 2 ) {
      printf( "YES %d\n\n", max[ 0 ] );
    }
    else {
      puts( "NO\n" );
    }
  }

  return 0;
}
