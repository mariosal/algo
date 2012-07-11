#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x, y;
} point;

int cmpX( const void *a, const void *b ) {
  if ( ( ( point* )a )->y == ( ( point* )b )->y ) {
    return ( ( point* )a )->x - ( ( point* )b )->x;
  }
  return ( ( point* )a )->y - ( ( point* )b )->y;
}
int cmpY( const void *a, const void *b ) {
  if ( ( ( point* )a )->x == ( ( point* )b )->x ) {
    return ( ( point* )a )->y - ( ( point* )b )->y;
  }
  return ( ( point* )a )->x - ( ( point* )b )->x;
}

int main() {
  int i, n, ans;
  point *a, *sort, *lowX, *lowY;

  freopen( "loutraki.in", "r", stdin );
  freopen( "loutraki.out", "w", stdout );

  scanf( "%d", &n );
  a = ( point* )malloc( n * sizeof( point ) );
  sort = ( point* )malloc( n * sizeof( point ) );
  lowX = ( point* )malloc( 200001 * sizeof( point ) );
  lowY = ( point* )malloc( 200001 * sizeof( point ) );
  for ( i = 0; i < 200001; ++i ) {
    lowX[ i ].x = 100001;
    lowY[ i ].x = 100001;
  }
  for ( i = 0; i < n; ++i ) {
    scanf( "%d %d", &a[ i ].x, &a[ i ].y );

    sort[ i ].x = a[ i ].x;
    sort[ i ].y = a[ i ].y;
  }

  qsort( sort, n, sizeof( point ), cmpX );
  for ( i = 0; i < n; ++i ) {
    if ( lowX[ sort[ i ].y + 100000 ].x == 100001 ) {
      lowX[ sort[ i ].y + 100000 ] = sort[ i ];
    }
  }

  qsort( sort, n, sizeof( point ), cmpY );
  for ( i = 0; i < n; ++i ) {
    if ( lowY[ sort[ i ].x + 100000 ].x == 100001 ) {
      lowY[ sort[ i ].x + 100000 ] = sort[ i ];
    }
  }

  ans = 0;
  for ( i = 0; i < n; ++i ) {
    if ( a[ i ].x == lowX[ a[ i ].y + 100000 ].x && a[ i ].y == lowX[ a[ i ].y + 100000 ].y &&
       a[ i ].x == lowY[ a[ i ].x + 100000 ].x && a[ i ].y == lowY[ a[ i ].x + 100000 ].y ) {
      ++ans;
    }
  }
  printf( "%d\n", ans );

  return 0;
}
