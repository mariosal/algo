#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *next ( const char *original, char times ) {
  if ( times <= 1 ) {
    char i, *transformed;
    size_t len;

    len = strlen( original );
    transformed = ( char* )malloc( len + 1 );

    transformed[ len ] = '\0';
    transformed[ len - 1 ] = original[ 0 ];
    for ( i = 0; i < len - 1; i += 1 ) {
      transformed[ i ] = original[ i + 1 ];
    }

    return transformed;
  }
  return next( next( original, 1 ), times - 1 );
}

int main() {
  char *string, *original, *transformed;
  short n, i, j;
  size_t len;

  freopen( "names.in", "r", stdin );
  freopen( "names.out", "w", stdout );

  string = ( char* )malloc( 21 );
  original = ( char* )malloc( 21 );
  transformed = ( char* )malloc( 21 );

  scanf( "%hd", &n );
  for ( i = 0; i < n; i += 1 ) {
    scanf( "%s", string );

    if ( i == 0 ) {
      strcpy( original, string );
      strcpy( transformed, string );
    }

    len = strlen( string );
    for ( j = 1; j <= len; j += 1 ) {
      if ( strcmp( transformed, next( string, j ) ) > 0 ) {
        strcpy( original, string );
        strcpy( transformed, next( string, j ) );
      }
    }
  }

  printf( "%s\n", original );

  return 0;
}
