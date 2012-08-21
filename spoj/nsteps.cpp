#include <cstdio>

int main() {
  short n, x, y, ans;

  scanf( "%hd", &n );
  while ( n-- ) {
    scanf( "%hd %hd", &x, &y );

    if ( y != x && y != x - 2 ) {
      printf( "No Number\n" );
      continue;
    }

    ans = 2 * x;
    if ( x % 2 ) {
      --ans;
    }
    if ( y == x - 2 ) {
      ans -= 2;
    }

    printf( "%hd\n", ans );
  }

  return 0;
}
