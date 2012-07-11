#include <stdio.h>
#include <math.h>

int main() {
  char i, ans;
  short cases, n, p, s, t;

  scanf( "%hd", &cases );
  for ( i = 1; i <= cases; ++i ) {
    scanf( "%hd %hd %hd", &n, &s, &p );

    ans = 0;
    while ( n-- ) {
      scanf( "%hd", &t );

      if ( p + p + p <= t || ( p + p - 1 + p - 1 <= t && p - 1 >= 0 ) ) {
        ++ans;
      }
      else if ( s && ( p + p - 1 + p - 2 == t || p + p - 2 + p - 2 == t ) && p - 2 >= 0 ) {
        ++ans;
        --s;
      }
    }
    printf( "Case #%d: %d\n", i, ans );
  }

  return 0;
}
