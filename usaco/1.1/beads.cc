/*
  ID: mariosa1
  LANG: C
  TASK: beads
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char color, *beads, *cat;
  short n, i, j, q, current, max;

  freopen( "beads.in", "r", stdin );
  freopen( "beads.out", "w", stdout );

  scanf( "%hd", &n );
  beads = ( char* )malloc( n + 1 );
  cat = ( char* )malloc( 2 * n + 1 );
  scanf( "%s", beads );

  max = 0;
  strncpy( cat, beads, n );
  strncat( cat, beads, n );
  for ( i = 0; i < n; i += 1 ) {
    color = cat[ i ];
    if ( color == 'w' ) {
      q = 0;
    }
    else {
      q = 1;
    }

    j = i;
    current = 0;
    for ( ; q <= 2; q += 1 ) {
      while ( j < n + i && ( cat[ j ] == color || cat[ j ] == 'w'  ) ) {
        current += 1;
        j += 1;
      }
      color = cat[ j ];
    }

    if ( max < current ) {
      max = current;
    }
  }

  printf( "%hd\n", max );

  return 0;
}
