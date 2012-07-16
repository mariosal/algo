#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  const char N = 80;
  char i, j;
  short k;
  int dp[ N ][ N ];

  for ( i = 0; i < N; ++i ) {
    for ( j = 0; j < N; ++j ) {
      scanf( "%hd", &k );
      if ( !i && !j ) {
        dp[ i ][ j ] = 0;
      }
      else if ( i == 0 ) {
        dp[ i ][ j ] = dp[ i ][ j - 1 ];
      }
      else if ( j == 0 ) {
        dp[ i ][ j ] = dp[ i - 1 ][ j ];
      }
      else {
        dp[ i ][ j ] = min( dp[ i - 1 ][ j ], dp[ i ][ j - 1 ] );
      }
      dp[ i ][ j ] += k;
    }
  }
  printf( "%d\n", dp[ N - 1 ][ N - 1 ] );

  return 0;
}
