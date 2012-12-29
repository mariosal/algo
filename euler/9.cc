#include <cstdio>

int main() {
  short a, b, c;

  for ( a = 0; a < 1000; ++a ) {
    for ( b = a + 1; b < 1000; ++b ) {
      c = 1000 - a - b;
      if ( b >= c ) {
        continue;
      }

      if ( a * a + b * b == c * c ) {
        printf( "%d\n", a * b * c );
        return 0;
      }
    }
  }

  return 0;
}
