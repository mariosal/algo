#include <cstdio>
#include <algorithm>

using namespace std;

int *h;

void init( int *a, int k, int b, int e ) {
  if ( b == e ) {
    h[ k ] = a[ b ];
  }
  else {
    init( a, 2 * k, b, ( b + e ) / 2 );
    init( a, 2 * k + 1, ( b + e ) / 2 + 1, e );
    h[ k ] = max( h[ 2 * k ], h[ 2 * k + 1 ] ); 
  }
}
int query( int i, int j, int k, int b, int e ) {
  if ( b > j || e < i ) {
    return 0;
  }
  if ( b >= i && e <= j ) {
    return h[ k ];
  }
  else {
    return max(
      query( i, j, 2 * k, b, ( b + e ) / 2 ),
      query( i, j, 2 * k + 1, ( b + e ) / 2 + 1, e )
    );
  }
}

int main() {
  short k;
  int i, n, *a;

  scanf( "%d", &n );
  a = new int[ n ];
  h = new int[ 4 * n ];
  for ( i = 0; i < n; ++i ) {
    scanf( "%d", a + i );
  }
  scanf( "%hd", &k );

  init( a, 1, 0, n - 1 );
  for ( i = 0; i + k - 1 < n; ++i ) {
    printf( "%s%d", i ? " " : "", query( i, i + k - 1, 1, 0, n - 1 ) );
  }
  printf( "\n" );

  return 0;
}
