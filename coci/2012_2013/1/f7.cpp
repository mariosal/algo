#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int i, j, n, ans, *a;

  scanf( "%d", &n );
  a = new int[ n ];

  for ( i = 0; i < n; ++i ) {
    scanf( "%d", &a[ i ] );
  }

  ans = 0;
  sort( a, a + n );
  for ( i = n - 1; i >= 0; --i ) {
    for ( j = n - 1; j > i; --j ) {
      if ( a[ i ] + n < a[ j ] + n - j ) {
        break;
      }
    }
    if ( j != i ) {
      break;
    }

    ++ans;
  }
  printf( "%d\n", ans );

  return 0;
}
