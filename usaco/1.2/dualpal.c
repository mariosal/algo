/*
  PROG: dualpal
  LANG: C
  ID: mariosa1
*/
#include <stdio.h>
long long base( short N, short base ) {
  long long i = 0, j = 1;

  while ( N > 0 ) {
    i += ( N % base ) * j;
    N /= base;
    j *= 10;
  }
  return i;
}
long long reverse( long long N ) {
  long long i = 0;

  while ( N > 0 ) {
    i *= 10;
    i += N % 10;
    N /= 10;
  }
  return i;
}
int main() {
  short N, i, j, S;
  freopen( "dualpal.in", "r", stdin );
  freopen( "dualpal.out", "w", stdout );
  scanf( "%hd %hd", &N, &S );
  for ( ++S; N; ++S ) {
    for ( i = 2, j = 0; i <= 10; ++i ) {
      if ( base( S, i ) == reverse( base( S, i ) ) ) {
        ++j;
      }
    }
    if ( j >= 2 ) {
      printf( "%hd\n", S );
      --N;
    }
  }
  return 0;
}
