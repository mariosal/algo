#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int value;
  int size;
} node;

int max( int a, int b ) {
  if ( a >= b ) {
    return a;
  }
  return b;
}

int main() {
  short n, j;
  unsigned short size;
  int i, maxSize, **best;
  node *item;

  freopen( "turtle.in", "r", stdin );
  freopen( "turtle.out", "w", stdout );

  scanf( "%hd %hu", &n, &size );
  maxSize = size;

  item = ( node* )malloc( n * sizeof( node ) );
  for ( i = 0; i < n; ++i ) {
    scanf( "%d", &item[ i ].size );
    item[ i ].value = item[ i ].size;
    if ( maxSize < item[ i ].size ) {
      maxSize = item[ i ].size;
    }
  }

  best = ( int** )malloc( ( n + 1 ) * sizeof( int* ) );
  for ( i = 0; i <= n; ++i ) {
    best[ i ] = ( int* )malloc( ( maxSize + 1 ) * sizeof( int ) );
    best[ i ][ 0 ] = 0;
  }
  for ( i = 0; i <= maxSize; ++i ) {
    best[ 0 ][ i ] = 0;
  }

  for ( i = 1; i <= maxSize; ++i ) {
    for ( j = 1; j <= n; ++j ) {
      if ( item[ j - 1 ].size <= i ) {
        best[ j ][ i ] = max( best[ j - 1 ][ i ], best[ j - 1 ][ i - item[ j - 1 ].size ] + item[ j - 1 ].value );
      }
      else {
        best[ j ][ i ] = best[ j - 1 ][ i ];
      }
    }
  }

  for ( i = 1; i <= maxSize; ++i ) {
    if ( best[ n ][ i ] >= size ) {
      printf( "%d\n", best[ n ][ i ] );
      break;
    }
  }

  return 0;
}
