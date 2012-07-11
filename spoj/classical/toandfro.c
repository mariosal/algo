#include <stdio.h>
#include <string.h>

int main() {
  char i;
  char s[ 201 ];
  short n, len, j, q, k;
  char a[ 1000 ][ 1000 ];

  while ( 1 ) {
    scanf( "%hd", &n );
    if ( !n ) {
      break;
    }

    scanf( "%s", s );

    i = 0;
    len = strlen( s );
    for ( q = k = 0; q < len / n; ++q ) {
      if ( i == 0 ) {
        for ( j = 0; j < n; ++j, ++k ) {
          a[ q ][ j ] = s[ k ];
        }

        i = 1;
      }
      else {
        for ( j = n - 1; j >= 0 ; --j, ++k ) {
          a[ q ][ j ] = s[ k ];
        }

        i = 0;
      }
    }

    for ( i = 0; i < n; ++i ) {
      for ( j = 0; j < len / n; ++j ) {
        putchar( a[ j ][ i ] );
      }
    }
    putchar( '\n' );
  }

  return 0;
}
