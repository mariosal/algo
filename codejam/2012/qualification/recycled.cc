#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>

using namespace std;

int rotateAll( int a, int max ) {
  char i, j, tmp, len, *s;
  int toi, ans;
  set< int > marked;

  ans = 0;
  len = floor( log10( a ) ) + 1;
  s = ( char* )malloc( len + 1 );
  sprintf( s, "%d", a );

  marked.insert( a );
  for ( i = 0; i < len; ++i ) {
    tmp = s[ 0 ];
    for ( j = 1; j < len; ++j ) {
      s[ j - 1 ] = s[ j ];
    }
    s[ len - 1 ] = tmp;

    toi = atoi( s );
    if ( toi < a || toi > max || marked.find( toi ) != marked.end() ) {
      continue;
    }
    marked.insert( toi );
    ++ans;
  }

  return ans;
}

int main() {
  char i;
  short t;
  int j, ans, a, b;

  scanf( "%hd", &t );
  for ( i = 1; i <= t; ++i ) {
    scanf( "%d %d", &a, &b );

    ans = 0;
    for ( j = a; j <= b; ++j ) {
      ans += rotateAll( j, b );
    }

    printf( "Case #%d: %d\n", i, ans );
  }

  return 0;
}
