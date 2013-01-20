#include <cstdio>
#include <list>

using namespace std;

int main() {
  short i, j, n;
  int *a;
  list< short > freq;
  list< short >::iterator it;

  freopen( "seti.in", "r", stdin );
  freopen( "seti.out", "w", stdout );

  scanf( "%hd", &n );
  a = new int[ n ];
  for ( i = 0; i < n; ++i ) {
    scanf( "%d", &a[ i ] );
  }

  for ( i = 1; i < n - 1; ++i ) {
    for ( j = 1; i >= j && i + j < n; ++j ) {
      if ( a[ i - j ] == a[ i + j ] && 2 * a[ i - j ] < a[ i ] ) {
        freq.push_back( i + 1 );
        break;
      }
    }
  }

  printf( "%hd\n", freq.size() );
  for ( it = freq.begin(); it != freq.end(); ++it ) {
    printf( "%hd\n", *it );
  }

  return 0;
}
