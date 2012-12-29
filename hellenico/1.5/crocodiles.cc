#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int i, j, k, sum, maxSum, n, a[ 200001 ];

  freopen( "crocodiles.in", "r", stdin );
  freopen( "crocodiles.out", "w", stdout );

  for ( i = 0; i <= 200000; ++i ) {
    a[ i ] = 0;
  }
  
  scanf( "%d", &n );
  for ( i = 0; i < n; ++i ) {
    scanf( "%d %d", &j, &k );
    j += 100000;
    k += 100000;
    ++a[ j ];
    --a[ k ];
  }

  sum = maxSum = 0;
  for ( i = 0; i <= 200000; ++i ) {
    sum = max( sum + a[ i ], a[ i ] );
    maxSum = max( maxSum, sum );
  }
  printf( "%d\n", maxSum );

  return 0;
}
