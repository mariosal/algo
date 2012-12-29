#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  char *s;
  short i, j, n, **lps;

  scanf( "%hd", &n );

  s = new char[ n ];
  scanf( "%s", s );

  lps = new short*[ 2 ];
  for ( i = 0; i < 2; ++i ) {
    lps[ i ] = new short[ n ];
  }

  for ( i = n - 1; i >= 0; --i ) {
    lps[ i % 2 ][ i ] = 1;

    for ( j = i + 1; j < n; ++j ) {
      if ( s[ i ] == s[ j ] ) {
        lps[ i % 2 ][ j ] = 2 + lps[ ( i + 1 ) % 2 ][ j - 1 ];
      }
      else {
        lps[ i % 2 ][ j ] = max( lps[ ( i + 1 ) % 2 ][ j ], lps[ i % 2 ][ j - 1 ] );
      }
    }
  }
  printf( "%hd\n", n - lps[ 0 ][ n - 1 ] );

  return 0;
}
