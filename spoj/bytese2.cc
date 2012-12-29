#include <cstdio>
#include <map>

using namespace std;

int main() {
  char maxDance;
  short t, n;
  int i, j, p, r;
  map< int, short > M;
  map< int, short >::iterator it;

  scanf( "%hd", &t );
  while ( t-- ) {
    scanf( "%hd", &n );

    for ( i = 0; i < n; ++i ) {
      scanf( "%d %d", &p, &r );
      for ( j = p; j < r; ++j ) {
        ++M[ j ];
      }
    }

    maxDance = 0;
    for ( it = M.begin(); it != M.end(); ++it ) {
      if ( it->second > maxDance ) {
        maxDance = it->second;
      }
      M.erase( it );
    }
    
    printf( "%d\n", maxDance );
  }

  return 0;
}
