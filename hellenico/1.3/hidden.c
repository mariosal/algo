#include "hiddenlib.h"

int main() {
  short cmp;
  int p = 1, r = getN(), q;
  
  do {
    q = ( p + r ) / 2;

    cmp = compare( p, r );
    if ( cmp == 1 ) {
      r = q - 1;
    }
    else if ( cmp == -1 ) {
      p = q + 1;
    }
  } while ( !ishidden( q ) );

  return 0;
}
