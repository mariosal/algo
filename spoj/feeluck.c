#include <stdio.h>

int main() {
  char A[ 10 ][ 101 ];
  short B[ 10 ];

  char i, j, max;
  short n;

  //freopen( "in.txt", "r", stdin );

  scanf( "%hd", &n );
  for ( i = 1; i <= n; ++i ) {
    max = 0;
    for ( j = 0; j < 10; ++j ) {
      scanf( "%s %hd", A[ j ], &B[ j ] );

      if ( max < B[ j ] ) {
        max = B[ j ];
      }
    }

    printf( "Case #%d:\n", i );
    for ( j = 0; j < 10; ++j ) {
      if ( B[ j ] == max ) {
        puts( A[ j ] );
      }
    }
  }

  return 0;
}
