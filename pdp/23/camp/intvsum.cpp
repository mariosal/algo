#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int main() {
  int i, n, ans, *a, *sums;
  map< int, int > m;
  map< int, int >::iterator it;

  scanf( "%d", &n );
  a = new int[ n ];
  sums = new int[ n ];
  for ( i = 0; i < n; ++i ) {
    scanf( "%d", &a[ i ] );

    if ( !i ) {
      sums[ i ] = a[ i ];
      m[ a[ i ] ] = i + 1;
    }
    else {
      sums[ i ] = sums[ i - 1 ] + a[ i ];
      m[ sums[ i - 1 ] - a[ i ] ] = i + 1;
    }
  }

  ans = 0;
  for ( i = 0; i < n; ++i ) {
    it = m.find( sums[ i ] + a[ i ] );
    if ( it != m.end() ) {
      ans = max( ans, it->second );
    }
  }
  printf( "%d\n", ans );

  return 0;
}
