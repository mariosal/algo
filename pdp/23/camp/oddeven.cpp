#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int i, j, n, *sums, ans;
  pair< int, int > *buckets;

  scanf( "%d", &n );
  sums = new int[ n ];
  buckets = new pair< int, int >[ 2 * n + 1 ];

  for ( i = 0; i <= 2 * n; ++i ) {
    buckets[ i ] = make_pair( -1, -1 );
  }

  for ( i = 0; i < n; ++i ) {
    scanf( "%d", &j );

    if ( !i ) {
      sums[ i ] = 0;
    }
    else {
      sums[ i ] = sums[ i - 1 ];
    }
    sums[ i ] += j % 2 ? 1 : -1;
  }

  for ( i = 0; i < n; ++i ) {
    if ( buckets[ sums[ i ] + n ].first == -1 ) {
      buckets[ sums[ i ] + n ].first = i;
    }
    else {
      buckets[ sums[ i ] + n ].second = i;
    }
  }

  ans = 0;
  for ( i = 0; i <= 2 * n; ++i ) {
    ans = max( ans, buckets[ i ].second - buckets[ i ].first );
  }
  printf( "%d\n", ans );

  return 0;
}
