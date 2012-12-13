#include <cstdio>
#include <algorithm>

using namespace std;

struct P {
  double x, y;
};

int n;
P *p;

int main() {
  int i;
  double area;
  P best;

  scanf( "%d", &n );
  p = new P[ n ];
  for ( i = 0; i < n; ++i ) {
    scanf( "%lf %lf", &p[ i ].x, &p[ i ].y );
    if ( i ) {
      p[ i ].y -= p[ 0 ].y;
    }
  }
  p[ 0 ].y = 0;

  best.y = ( p[ 0 ].y + p[ n - 1 ].y ) / 2;
  for ( i = 0; p[ i ].y < best.y; ++i );
  best.x = ( best.y - p[ i ].y ) / ( ( p[ i ].y - p[ i - 1 ].y ) / ( p[ i ].x - p[ i - 1 ].x ) ) + p[ i ].x;

  area = 0;
  for ( i = 1; p[ i ].x < best.x; ++i ) {
    area += ( p[ i ].x - p[ i - 1 ].x ) * ( p[ i ].y - p[ i - 1 ].y ) / 2 + ( p[ i ].x - p[ i - 1 ].x ) * p[ i - 1 ].y;
  }
  area += ( best.x - p[ i - 1 ].x ) * ( best.y - p[ i - 1 ].y ) / 2 + ( best.x - p[ i - 1 ].x ) * p[ i - 1 ].y;
  area += ( p[ i ].x - best.x ) * ( p[ i ].y - best.y ) / 2 + ( p[ i ].x - best.x ) * ( p[ n - 1 ].y - p[ i ].y );
  for ( i++; i < n ; ++i ) {
    area += ( p[ i ].x - p[ i - 1 ].x ) * ( p[ i ].y - p[ i - 1 ].y ) / 2 + ( p[ i ].x - p[ i - 1 ].x ) * ( p[ n - 1 ].y - p[ i ].y );
  }
  printf( "%.6lf\n", area );

  return 0;
}
