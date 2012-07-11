/*
  PROG: calfflac
  ID: marisa1
  LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main() {
  char *buffer, *new;
  short i, j, nsize, max, mini, maxj, *pos;
  long size;
  freopen( "calfflac.in", "r", stdin );
  freopen( "calfflac.out", "w", stdout );
  fseek( stdin, 0, SEEK_END );
  size = ftell( stdin );
  rewind( stdin );
  buffer = ( char* )malloc( size );
  new = ( char* )malloc( size );
  pos = ( short* )malloc( sizeof( short ) * size );
  fread( buffer, 1, size, stdin );
  for ( i = nsize = 0; i < size; ++i ) {
    if ( isalpha( buffer[ i ] ) ) {
      new[ nsize ] = tolower( buffer[ i ] );
      pos[ nsize ] = i;
      ++nsize;
    }
  }
  max = 0;
  for ( i = 0; i < nsize; ++i ) {
    j = 1;
    while ( i - j >= 0 && i + j < nsize ) {
      if ( new[ i - j ] == new[ i + j ] ) {
        ++j;
      }
      else {
        break;
      }
    }
    if ( max < j * 2 - 1 ) {
      max = j * 2 - 1;
      mini = pos[ i - j + 1 ];
      maxj = pos[ i + j - 1 ];
    }
    j = 0;
    while ( i - j >= 0 && i + j + 1 < nsize ) {
      if ( new[ i - j ] == new[ i + j + 1 ] ) {
        ++j;
      }
      else {
        break;
      }
    }
    if ( max < j * 2 ) {
      max = j * 2;
      mini = pos[ i - j + 1 ];
      maxj = pos[ i + j ];
    }
  }
  printf( "%hd\n", max );
  for ( ; mini <= maxj; ++mini ) {
    putchar( buffer[ mini ] );
  }
  putchar( '\n' );
  return 0;
}
