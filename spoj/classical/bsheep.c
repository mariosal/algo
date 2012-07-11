#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  short x, y;
  int id;
} point;

point min;

int cross( point a, point b, point c ) {
  return ( int )( b.x - a.x ) * ( c.y - a.y ) - ( b.y - a.y ) * ( c.x - a.x );
}
int distance2( point a, point b ) {
  return ( int )( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y );
}

int compare( const void *a, const void *b ) {
  int d, d2, wise;

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
  if ( d > d2 ) {
    return 1;
  }

  return ( ( point* )a )->id - ( ( point* )b )->id;
}

int main() {
  short t;
  int n, m, i;
  float circ;
  point *p, *hull;

  scanf( "%hd", &t );
  while ( t-- ) {
    scanf( "%d", &n );
    p = ( point* )malloc( n * sizeof( point ) );
    hull = ( point* )malloc( n * sizeof( point ) );

    for ( i = 0; i < n; i += 1 ) {
      scanf( "%hd %hd", &p[ i ].x, &p[ i ].y );
      p[ i ].id = i + 1;

      if ( !i || min.y > p[ i ].y || ( min.y == p[ i ].y && min.x > p[ i ].x ) ) {
        min = p[ i ];
      }
    }

    qsort( p, n, sizeof( point ), compare );
    m = 0;
    for ( i = 0; i < n; i += 1 ) {
      if ( i && p[ i ].x == p[ i - 1 ].x && p[ i ].y == p[ i - 1 ].y ) {
        continue;
      }

      while ( m >= 2 && cross( hull[ m - 2 ], hull[ m - 1 ], p[ i ] ) <= 0 ) {
        m -= 1;
      }

      hull[ m ] = p[ i ];
      m += 1;
    }

    circ = 0;
    for ( i = 0; i < m; i += 1 ) {
      circ += sqrt( distance2( hull[ i ], hull[ ( i + 1 ) % m ] ) );
    }

    printf( "%.2f\n", circ );
    for ( i = 0; i < m; i += 1 ) {
      printf( "%d%c", hull[ i ].id, i + 1 == m ? '\n' : ' ' );
    }
    if ( t ) {
      putchar( '\n' );
    }

    free( p );
    free( hull );
  }

  return 0;
}
