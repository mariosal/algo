#include <cstdio>
#include <cmath>

bool canMove( double *p, int n, int d, double t ) {
  int i;
  double prev, cur;

  prev = p[ 0 ] - t;
  for ( i = 1; i < n; ++i ) {
    cur = p[ i ];
    if ( cur < prev + d && prev + d - cur > t ) {
      return false;
    }
    if ( cur - prev - d > t ) {
      cur -= t;
    }
    else {
      cur = prev + d;
    }
    prev = cur;
  }
  return true;
}

double bSearch( double *p, int n, int d, double i, double j ) {
  double k = ( i + j ) / 2;

  if ( i > j ) {
    return 0;
  }
  if ( fabs( i - j ) < 1e-2 ) {
    return k;
  }
  if ( canMove( p, n, d, k ) ) {
    return bSearch( p, n, d, i, k );
  }
  return bSearch( p, n, d, k, j );
}

int main() {
  const int V = 1000000;
  short k, t;
  int j, c, n, d;
  long long i;
  double x, *p = new double[ V ];

  scanf( "%hd", &t );
  for ( k = 1; k <= t; ++k ) {
    scanf( "%d %d", &c, &d );

    n = 0;
    for ( i = 0; i < c; ++i ) {
      scanf( "%lf %d", &x, &j );
      while ( j-- ) {
        p[ n++ ] = x;
      }
    }

    for ( i = 2; !canMove( p, n, d, i ); i *= 2 );
    printf( "Case #%d: %.2lf\n", k, bSearch( p, n, d, i == 2 ? 0 : i / 2, i ) );
  }

  return 0;
}
