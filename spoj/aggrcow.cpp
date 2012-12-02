#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n, c, *s;

bool f( int d ) {
  int i = 0, j = c - 1, prev = s[ 0 ];
  while ( j ) {
    i = lower_bound( s, s + n, prev + d ) - s;
    if ( i >= n ) {
      break;
    }

    prev = s[ i ];
    --j;
  }
  return !j;
}

int binarySearch( int i, int j ) {
  while ( 1 ) {
    if ( i == j ) {
      return i;
    }
    if ( j - i == 1 ) {
      return f( j ) ? j : i;
    }
    if ( f( ( i + j ) / 2 ) ) {
      i = ( i + j ) / 2;
    }
    else {
      j = ( i + j ) / 2 - 1;
    }
  }
}

int main() {
  int t, i;

  scanf( "%d", &t );
  while ( t-- ) {
    scanf( "%d %d", &n, &c );
    s = new int[ n ];

    for ( i = 0; i < n; ++i ) {
      scanf( "%d", s + i );
    }
    sort( s, s + n );

    printf( "%d\n", binarySearch( 1, s[ n - 1 ] - s[ 0 ] ) );

    delete[] s;
  }

  return 0;
}
