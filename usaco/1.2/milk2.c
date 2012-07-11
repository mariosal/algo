/*
  ID: mariosa1
  LANG: C
  TASK: milk2
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int start;
  int end;
} Event;

int compare( const void *a, const void *b ) {
  return ( ( Event* )a )->start - ( ( Event* )b )->start;
}

int main() {
  short n, i;
  int start, end, work, idle;
  Event *milk;

  freopen( "milk2.in", "r", stdin );
  freopen( "milk2.out", "w", stdout );

  scanf( "%hd", &n );
  milk = ( Event* )malloc( n * sizeof( Event ) );

  for ( i = 0; i < n; i += 1 ) {
    scanf( "%d %d", &milk[ i ].start, &milk[ i ].end );
  }

  qsort( milk, n, sizeof( Event ), compare );

  start = end = work = idle = 0;
  for ( i = 0; i < n; i += 1 ) {
    if ( milk[ i ].start <= end ) {
      if ( milk[ i ].end > end ) {
        end = milk[ i ].end;
      }
    }
    else {
      if ( end && idle < milk[ i ].start - end ) {
        idle = milk[ i ].start - end;
      }

      start = milk[ i ].start;
      end = milk[ i ].end;
    }

    if ( work < end - start ) {
      work = end - start;
    }
  }

  printf( "%d %d\n", work, idle );

  return 0;
}
