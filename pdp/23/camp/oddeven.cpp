#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int i, j, n, sum, ans;
  pair< int, int > *buckets;

  scanf( "%d", &n );
  buckets = new pair< int, int >[ 2 * n + 1 ];

  for ( i = 0; i <= 2 * n; ++i ) {
    buckets[ i ] = make_pair( -1, -1 );
  }

  sum = 0;
  buckets[ n ] = make_pair( 0, 0 );
  for ( i = 1; i <= n; ++i ) {
    scanf( "%d", &j );
    sum += j % 2 ? 1 : -1;

    if ( buckets[ sum + n ].first == -1 ) {
      buckets[ sum + n ].first = i;
    }
    buckets[ sum + n ].second = i;
  }

  ans = 0;
  for ( i = 0; i <= 2 * n; ++i ) {
    ans = max( ans, buckets[ i ].second - buckets[ i ].first );
  }
  printf( "%d\n", ans );

  return 0;
}
