#include <cstdio>
#include <cstring>

short n;
int **bit;

void update( short x, short y, int v ) {
  short y1;
  while ( x <= n ) {
    y1 = y;
    while ( y1 <= n ) {
      bit[ x ][ y1 ] += v;
      y1 += y1 & -y1;
    }
    x += x & -x;
  }
}
int sum( short x, short y ) {
  short y1;
  int ret = 0;
  while ( x > 0 ) {
    y1 = y;
    while ( y1 > 0 ) {
      ret += bit[ x ][ y1 ];
      y1 -= y1 & -y1;
    }
    x -= x & -x;
  }
  return ret;
}

int main() {
  char cmd[ 4 ];
  short x1, y1, x2, y2;
  int t, v;

  scanf( "%d", &t );
  while ( t-- ) {
    scanf( "%hd", &n );

    bit = new int*[ n + 1 ];
    for ( x1 = 0; x1 <= n; ++x1 ) {
      bit[ x1 ] = new int[ n + 1 ];
      for ( y1 = 0; y1 <= n; ++y1 ) {
        bit[ x1 ][ y1 ] = 0;
      }
    }

    while ( scanf( "%s", cmd ) ) {
      if ( !strcmp( cmd, "SET" ) ) {
        scanf( "%hd %hd %d", &x1, &y1, &v );
        update( x1 + 1, y1 + 1, -( sum( x1 + 1 , y1 + 1 ) - sum( x1, y1 + 1 ) - sum( x1 + 1, y1 ) + sum( x1, y1 ) ) );
        update( x1 + 1, y1 + 1, v );
      }
      else if ( !strcmp( cmd, "SUM" ) ) {
        scanf( "%hd %hd %hd %hd", &x1, &y1, &x2, &y2 );
        printf( "%d\n", sum( x2 + 1, y2 + 1 ) - sum( x1, y2 + 1 ) - sum( x2 + 1, y1 ) + sum( x1, y1 ) );
      }
      else {
        break;
      }
    }

    for ( x1 = 0; x1 <= n; ++x1 ) {
      delete[] bit[ x1 ];
    }
    delete[] bit;
  }

  return 0;
}
