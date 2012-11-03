#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Building {
  short h, c;
};
bool operator <( Building a, Building b ) {
  if ( a.h == b.h ) {
    return a.c < b.c;
  }
  return a.h < b.h;
}

short n;
Building *b;

long long f( short x ) {
  short i;
  long long ret;

  ret = 0;
  for ( i = 0; i < n; ++i ) {
    ret += abs( b[ x ].h - b[ i ].h ) * b[ i ].c;
  }
  return ret;
}

long long tSearch( short p, short s ) {
  short q, r;
  long long ret;

  while ( s - p >= 3 ) {
    q = ( 2 * p + s ) / 3;
    r = ( 2 * s + p ) / 3;

    if ( f( q ) > f( r ) ) {
      p = q;
    }
    else {
      s = r;
    }
  }

  ret = f( p );
  for ( ++p; p <= s; ++p ) {
    ret = min( ret, f( p ) );
  }
  return ret;
}

int main() {
  short t, i;

  scanf( "%hd", &t );
  while ( t-- ) {
    scanf( "%hd", &n );
    b = new Building[ n ];

    for ( i = 0; i < n; ++i ) {
      scanf( "%hd", &b[ i ].h );
    }
    for ( i = 0; i < n; ++i ) {
      scanf( "%hd", &b[ i ].c );
    }
    sort( b, b + n );

    printf( "%lld\n", tSearch( 0, n - 1 ) );

    delete[] b;
  }

  return 0;
}
