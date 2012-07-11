/*
  PROG: milk
  ID: mariosa1
  LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
int cmp( const void *a, const void *b ) {
  return *( int* )a - *( int* )b;
}
int main() {
  short i, M;
  int N, cost, amount;
  freopen( "milk.in", "r", stdin );
  freopen( "milk.out", "w", stdout );
  scanf( "%d %hd", &N, &M );
  int milk[ M ][ 2 ];
  for ( i = 0; i < M; ++i ) {
    scanf( "%d %d", &milk[ i ][ 0 ], &milk[ i ][ 1 ] );
  }
  qsort( milk, M, 2 * sizeof( int ), cmp );
  amount = cost = 0;
  for ( i = 0; i < M; ++i ) {
    if ( N == amount ) {
      break;
    }
    if ( N >= amount + milk[ i ][ 1 ] ) {
      cost   += milk[ i ][ 0 ] * milk[ i ][ 1 ];
      amount += milk[ i ][ 1 ];
    }
    else {
      cost   += milk[ i ][ 0 ] * ( N - amount );
      amount += N - amount;
    }
  }
  
  printf( "%d\n", cost );
  return 0;
}
