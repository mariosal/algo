#include <stdio.h>

int main() {
  int I, W;

  while ( 1 ) {
    scanf( "%d %d", &I, &W );
    if ( I == -1 ) {
      break;
    }

    if ( ( long double )I / W == ( long double )1000 / 37 ) {
      puts( "Y" );
    }
    else {
      puts( "N" );
    }
  }

  return 0;
}
