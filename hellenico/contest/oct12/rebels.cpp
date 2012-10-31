#include <cstdio>
#include <cmath>

int main() {
  short n;
  int i, sum, *rebel;
  float truck, ans;

  freopen( "rebels.in", "r", stdin );
  freopen( "rebels.out", "w", stdout );

  scanf( "%*c %hd", &n );
  rebel = new int[ n ];

  sum = 0;
  scanf( "%f", &truck );
  for ( i = 0; i < n; ++i ) {
    scanf( "%d", &rebel[ i ] );
    sum += rebel[ i ];
  }
  
  ans = fabs( truck - ( float )sum / n );
  for ( i = 0; i < n; ++i ) {
    ans += fabs( rebel[ i ] - ( float )sum / n );
  }
  printf( "%.0lf\n", ans );

  return 0;
}
