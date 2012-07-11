#include <stdio.h>

int main() {
  short T, N, A, D;
  int i;

  scanf( "%hd", &T );
  while ( T-- ) {
    scanf( "%hd %hd %hd", &N, &A, &D );

    i = 0;
    while ( N-- ) {
      i += A;
      A += D;
    }
    printf( "%d\n", i );
  }

  return 0;
}
