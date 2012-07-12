#include <stdio.h>
#include <string.h>

int main() {
  char seg[ 51 ];
  short t;

  scanf( "%hd", &t );
  while ( t-- ) {
    scanf( "%s", seg );
    if ( strchr( seg, 'D' ) == NULL ) {
      printf( "Possible\n" );
    }
    else {
      printf( "You shall not pass!\n" );
    }
  }

  return 0;
}
