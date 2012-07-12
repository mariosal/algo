#include <stdio.h>

int main() {
  char i, j;

  puts( "Ready" );
  while ( 1 ) {
    i = getchar();
    j = getchar();
    getchar();

    if ( i == ' ' ) {
      break;
    }

    if ( ( i + j == 'b' + 'd' ) || ( i + j == 'p' + 'q' ) ) {
      puts( "Mirrored pair" );
    }
    else {
      puts( "Ordinary pair" );
    }
  }

  return 0;
}
