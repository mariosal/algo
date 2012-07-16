#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  const char N = 80;
  char i, j;
  short k;
  int w[ N ][ N ];

  for ( i = 0; i < N; ++i ) {
    for ( j = 0; j < N; ++j ) {
      scanf( "%hd", &k );
      if ( !i && !j ) {
        w[ i ][ j ] = 0;
      }
      else if ( i == 0 ) {
        w[ i ][ j ] = w[ i ][ j - 1 ];
      }
      else if ( j == 0 ) {
        w[ i ][ j ] = w[ i - 1 ][ j ];
      }
      else {
        w[ i ][ j ] = min( w[ i - 1 ][ j ], w[ i ][ j - 1 ] );
      }
      w[ i ][ j ] += k;
    }
  }
  printf( "%d\n", w[ N - 1 ][ N - 1 ] );

  return 0;
}
