#include <cstdio>
#include <algorithm>

using namespace std;

struct Node {
  int s, ms, ls, rs;
};
Node *h;

void init( short *a, int k, short b, short e ) {
  if ( b == e ) {
    h[ k ] = ( Node ) {
      a[ b ], a[ b ], a[ b ], a[ b ]
    };
  }
  else {
    init( a, 2 * k, b, ( b + e ) / 2 );
    init( a, 2 * k + 1, ( b + e ) / 2 + 1, e );

    h[ k ] = ( Node ) {
      h[ 2 * k ].s + h[ 2 * k + 1 ].s,
      max( h[ 2 * k ].rs + h[ 2 * k + 1 ].ls, max( h[ 2 * k ].ms, h[ 2 * k + 1 ].ms ) ),
      max( h[ 2 * k ].ls, h[ 2 * k ].s + h[ 2 * k + 1 ].ls ),
      max( h[ 2 * k + 1 ].rs, h[ 2 * k + 1 ].s + h[ 2 * k ].rs )
    };
  }
}
Node q( short i, short j, int k, short b, short e ) {
  if ( i > j ) {
    return ( Node ) { 0, 0, 0, 0 };
  }
  if ( b == i && e == j ) {
    return h[ k ];
  }
  if ( j <= ( b + e ) / 2 ) {
    return q( i, j, 2 * k, b, ( b + e ) / 2 );
  }
  if ( i > ( b + e ) / 2 ) {
    return q( i, j, 2 * k + 1, ( b + e ) / 2 + 1, e );
  }

  Node l = q( i, ( b + e ) / 2, 2 * k, b, ( b + e ) / 2 );
  Node r = q( ( b + e ) / 2 + 1, j, 2 * k + 1, ( b + e ) / 2 + 1, e );

  return ( Node ) {
    l.s + r.s,
    max( l.rs + r.ls, max( l.ms, r.ms ) ),
    max( l.ls, l.s + r.ls ),
    max( r.rs, r.s + l.rs )
  };
}

int main() {
  char t;
  short n, m, i, j, x1, y1, x2, y2, *a;
  int ans;

  scanf( "%c", &t );
  while ( t-- != '0' ) {
    scanf( "%hd", &n );

    a = new short[ n + 1 ];
    h = new Node[ 4 * n ];

    for ( i = 1; i <= n; ++i ) {
      scanf( "%hd", &a[ i ] );
    }
    init( a, 1, 1, n );

    scanf( "%hd", &m );
    while ( m-- ) {
      scanf( "%hd %hd %hd %hd", &x1, &y1, &x2, &y2 );
      if ( y1 < x2 ) {
        ans = q( x1, y1, 1, 1, n ).rs + q( y1 + 1, x2 - 1, 1, 1, n ).s + q( x2, y2, 1, 1, n ).ls;
      }
      else {
        ans = max(
          q( x2, y1, 1, 1, n ).ms,
          max(
            q( x1, x2 - 1, 1, 1, n ).rs + q( x2, y2, 1, 1, n ).ls,
            q( x1, y1, 1, 1, n ).rs + q( y1 + 1, y2, 1, 1, n ).ls
          )
        );
      }
      printf( "%d\n", ans );
    }

    delete[] a;
    delete[] h;
  }

  return 0;
}
