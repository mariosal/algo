#include <cstdio>
#include <cmath>

short l, w;
int n, *h;
long long k;

double bSearch( double p, double r ) {
  int i;
  double diff, q = ( p + r ) / 2;

  if ( r - p < 1e-6 ) {
    return q;
  }

  diff = 0;
  for ( i = 0; i < n; ++i ) {
    if ( h[ i ] > q ) {
      diff += sqrt( h[ i ] - q );
    }
  }
  diff *= sqrt( l * w );

  if ( diff > k ) {
    return bSearch( q, r );
  }
  return bSearch( p, q );
}

int main() {
  int i, maxHeight;
  double ans, bestHeight;

  freopen( "aquarium.in", "r", stdin );
  freopen( "aquarium.out", "w", stdout );

  scanf( "%d %hd %hd %lld", &n, &l, &w, &k );
  h = new int[ n ];

  maxHeight = 0;
  for ( i = 0; i < n; ++i ) {
    scanf( "%d", &h[ i ] );
    if ( maxHeight < h[ i ] ) {
      maxHeight = h[ i ];
    }
  }

  bestHeight = bSearch( 0, maxHeight );

  ans = 0;
  for ( i = 0; i < n; ++i ) {
    if ( h[ i ] > bestHeight ) {
      ans += bestHeight;
    }
    else {
      ans += h[ i ];
    }
  }
  ans *= l * w;

  printf( "%.3lf\n", ans );

  return 0;
}
