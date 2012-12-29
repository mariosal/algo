#include <cstdio>

int main() {
  short i, j, k, n;
  int ans;

  while ( 1 ) {
    scanf( "%hd", &n );
    if ( !n ) {
      break;
    }

    ans = 0;
    for ( i = 1; i <= n; ++i ) {
      for ( j = 1; j <= n; ++j ) {
        for ( k = 0; i + k <= n && j + k <= n; ++k ) {
          ++ans;
        }
      }
    }
    printf( "%d\n", ans );
  }

  return 0;
}
