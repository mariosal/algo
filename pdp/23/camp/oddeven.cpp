#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int i, j, n, *sums, ans;
  pair< int, int > *buckets;

  scanf( "%d", &n );
  sums = new int[ n + 1 ];
  buckets = new pair< int, int >[ 2 * n + 1 ];

  for ( i = 0; i <= 2 * n; ++i ) {
    buckets[ i ] = make_pair( -1, -1 );
  }

  sums[ 0 ] = 0;
  for ( i = 1; i <= n; ++i ) {
    scanf( "%d", &j );
    sums[ i ] = sums[ i - 1 ] + ( j % 2 ? 1 : -1 );
  }

  for ( i = 0; i <= n; ++i ) {
    if ( buckets[ sums[ i ] + n ].first == -1 ) {
      buckets[ sums[ i ] + n ].first = i;
    }
    buckets[ sums[ i ] + n ].second = i;
  }

  ans = 0;
  for ( i = 0; i <= 2 * n; ++i ) {
    ans = max( ans, buckets[ i ].second - buckets[ i ].first );
  }
  printf( "%d\n", ans );

  return 0;
}
