#include <cstdio>
#include <cstdlib>

short n;
int truck, *rebel;

long long f( int x ) {
  short i;
  long long ret;

  ret = llabs( ( long long )truck - x );
  for ( i = 0; i < n; ++i ) {
    ret += llabs( ( long long )rebel[ i ] - x );
  }
  return ret;
}

long long tSearch( int p, int s ) {
  int q, r;
  long long ret;

  while ( ( long long )s - p >= 3 ) {
    q = ( 2LL * p + s ) / 3;
    r = ( p + 2LL * s ) / 3;

    if ( f( q ) < f( r ) ) {
      s = r;
    }
    else {
      p = q;
    }
  }

  ret = f( p );
  for ( ++p; p <= s; ++p ) {
    if ( ret > f( p ) ) {
      ret = f( p );
    }
  }
  return ret;
}

int main() {
  short i;
  int minCoord, maxCoord;

  //freopen( "rebels.in", "r", stdin );
  //freopen( "rebels.out", "w", stdout );

  scanf( "%*c %hd", &n );
  rebel = new int[ n ];

  scanf( "%d", &truck );
  minCoord = maxCoord = truck;
  for ( i = 0; i < n; ++i ) {
    scanf( "%d", &rebel[ i ] );
    if ( minCoord > rebel[ i ] ) {
      minCoord = rebel[ i ];
    }
    if ( maxCoord < rebel[ i ] ) {
      maxCoord = rebel[ i ];
    }
  }
  printf( "%lld\n", tSearch( minCoord, maxCoord ) );

  return 0;
}
