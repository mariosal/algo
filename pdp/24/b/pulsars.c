#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned short x, y;
  int id;
} point;

point min;

int cross( point a, point b, point c ) {
  return ( int )( b.x - a.x ) * ( c.y - a.y ) - ( b.y - a.y ) * ( c.x - a.x );
}
unsigned distance2( point a, point b ) {
  return ( unsigned )( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y );
}

int pCompare( const void *a, const void *b ) {
  int wise;
  unsigned d, d2;

  wise = cross( min, *( point* )a, *( point* )b );
  if ( wise > 0 ) {
    return -1;
  }
  if ( wise < 0 ) {
    return 1;
  }

  d = distance2( min, *( point* )a );
  d2 = distance2( min, *( point* )b );
  if ( d < d2 ) {
    return -1;
  }
  return 1;
}
int hCompare( const void *a, const void *b ) {
  return ( ( point* )a )->id - ( ( point* )b )->id;
}

int main() {
  int n, m, i;
  point *p, *hull;

  freopen( "pulsars.in", "r", stdin );
  freopen( "pulsars.out", "w", stdout );

  scanf( "%d", &n );
  p = ( point* )malloc( n * sizeof( point ) );
  hull = ( point* )malloc( n * sizeof( point ) );

  for ( i = 0; i < n; i += 1 ) {
    scanf( "%hu %hu", &p[ i ].x, &p[ i ].y );
    p[ i ].id = i + 1;

    if ( !i || min.y > p[ i ].y || ( min.y == p[ i ].y && min.x > p[ i ].x ) ) {
      min = p[ i ];
    }
  }

  qsort( p, n, sizeof( point ), pCompare );
  m = 0;
  for ( i = 0; i < n; i += 1 ) {
    while ( m >= 2 && cross( hull[ m - 2 ], hull[ m - 1 ], p[ i ] ) <= 0 ) {
      m -= 1;
    }

    hull[ m ] = p[ i ];
    m += 1;
  }

  qsort( hull, m, sizeof( point ), hCompare );
  printf( "%d\n", m );
  for ( i = 0; i < m; i += 1 ) {
    printf( "%d\n", hull[ i ].id );
  }

  return 0;
}
