#include <stdio.h>

int main() {
  short n;
  while ( 1 ) {
    scanf( "%hd", &n );
    if ( n == 42 ) {
      break;
    }
    printf( "%hd\n", n );
  }

  return 0;
}
