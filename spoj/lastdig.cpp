#include <cstdio>

char power( char a, int b, char m ) {
  char i;

  if ( b == 0 ) {
    return 1;
  }
  if ( b == 1 ) {
    return a % m;
  }
  i = power( a, b / 2, m );
  return ( ( i * i ) % m * power( a, b % 2, m ) ) % m;
}

int main() {
  short t, a;
  int b;

  scanf( "%hd", &t );
  while ( t-- ) {
    scanf( "%hd %d", &a, &b );
    printf( "%d\n", power( a, b, 10 ) );
  }

  return 0;
}
