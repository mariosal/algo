#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct {
  short cost;
  int left;
  int right;
} Game;

int n, maxRight, **memo;
Game *games;

int w( int i, int j ) {
  if ( i >= n || j > maxRight ) {
    return 0;
  }
  if ( memo[ i ][ j ] != -1 ) {
    return memo[ i ][ j ];
  }
  
  memo[ i ][ j ] = w( i + 1, j + 1 );
  if ( games[ i ].left <= j ) {
    memo[ i ][ j ] = max( memo[ i ][ j ], w( i + games[ i ].right + 1, games[ i ].right ) + games[ i ].cost );
  }
  return memo[ i ][ j ];
}

int main() { 
  int i, j;

  freopen( "lunapark.in", "r", stdin );
  freopen( "lunapark.out", "w", stdout );

  scanf( "%d", &n );
  games = new Game[ n ];
  maxRight = 0;
  for ( i = 0; i < n; ++i ) {
    scanf( "%hd %d %d", &games[ i ].cost, &games[ i ].left, &games[ i ].right );
    maxRight = max( maxRight, games[ i ].right );
  }

  maxRight += 2;
  memo = new int*[ n ];
  for ( i = 0; i < n; ++i ) {
    memo[ i ] = new int[ maxRight + 1 ];
    for ( j = 0; j <= maxRight; ++j ) {
      memo[ i ][ j ] = -1;
    }
  }

  printf( "%d\n", w( 0, 0 ) );

  return 0;
}
