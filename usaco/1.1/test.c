/*
  ID: mariosa1
  LANG: C
  TASK: test
*/
#include <stdio.h>

int main() {
  short a, b;

  freopen( "test.in", "r", stdin );
  freopen( "test.out", "w", stdout );

  scanf( "%hd %d", &a, &b );
  printf( "%hd\n", a + b );

  return 0;
}
