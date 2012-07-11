#include <cstdio>

int main() {
  short *a;
  int i, j, n, k;
  long long maxSum, curSum;

  freopen( "maxksum.in", "r", stdin );
  freopen( "maxksum.out", "w", stdout );

  scanf( "%d %d", &n, &k );
  a = new short[ n + 1 ];
  for ( i = 0; i < n; ++i ) {
    scanf( "%hd", &a[ i ] );
  }
  
  maxSum = 0;
  for ( i = 0; i < n; ++i ) {
    curSum = 0;
    for ( j = i; j - i < k && j < n; ++j ) {
      curSum += a[ j ];
      if ( maxSum < curSum ) {
        maxSum = curSum;
      }
    }
  }
  printf( "%lld\n", maxSum );

  return 0;
}
