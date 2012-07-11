/*
  PROG: palsquare
  LANG: C
  ID: mariosa1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap( char *a, char *b ) {
  char t = *a;
  *a = *b;
  *b = t;
}
char *reverse( char *A ) {
  short i, j;
  for ( j = 0; A[ j ] != '\0'; ++j );
  --j;
  for ( i = 0; i <= j / 2; ++i ) {
    swap( &A[ i ], &A[ j - i ] );
  }
  return A;
}
char *base( long long N, short base ) {
  char i;
  char *A = ( char* )malloc( 18 );
  short j = 0;
  
  while ( N > 0 ) {
    if ( N % base < 10 ) {
      i = N % base + '0';
    }
    else {
      i = N % base - 10 + 'A';
    }
    A[ j++ ] = i;
    N /= base;
  }
  return reverse( A );
}
int main() {
  short N, B;
  freopen( "palsquare.in", "r", stdin );
  freopen( "palsquare.out", "w", stdout );
  scanf( "%hd", &B );
  for ( N = 1; N <= 300; ++N ) {
    if ( strcmp( base( N * N, B ), reverse( base( N * N, B ) ) ) == 0 ) {
      printf( "%s %s\n", base( N, B ), base( N * N, B ) );
    }
  }
  return 0;
}
