#include <cstdio>

int power( int a, char n ) {
  int i;

  if ( n == 0 ) {
    return 1;
  }
  if ( n == 1 ) {
    return a;
  }
  i = power( a, n / 2 );
  return i * i * power( a, n % 2 );
}

int main() {
  printf( "%d\n", power( 2, 15 ) );
  printf( "%d\n", power( 10, 5 ) );
  printf( "%d\n", power( 4, 2 ) );

  return 0;
}
