/*
  PROG: ariprog
  LANG: C
  ID: mariosa1
*/
#include <stdio.h>
int main() {
  char S[ 135200 ], find, count;
  int a, b, len, N, M;
  freopen( "ariprog.in", "r", stdin );
  freopen( "ariprog.out", "w", stdout );
  scanf( "%d\n%d", &N, &M );
  for ( a = 0; a <= M; ++a ) {
    for ( b = a; b <= M; ++b ) {
      S[ a * a + b * b ] = 1;
    }
  }
  count = 0;
  for ( b = 1; b <= M * M; ++b ) {
    for ( a = 0; a <= M * M * 2 - b * ( N-1 ); ++a ) {
      if ( !S[ a ] ) {
        continue;
      }
      find = 1;
      for ( len = 1; len < N; ++len ) {
        if ( !S[ a + len * b ] ) {
          find = 0;
          break;
        }
      }
      if ( find ) {
        count = 1;
        printf( "%hu %hu\n", a, b );
      }
    }
  }
  if ( !count ) {
    puts( "NONE" );
  }
  return 0;
}
