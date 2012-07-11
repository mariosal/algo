#include <cstdio>

int reverse( int n ) {
  int ret;

  ret = 0;
  while ( n ) {
    ret *= 10;
    ret += n % 10;
    n /= 10;
  }
  return ret;
}

int main() {
  int n, a, b;

  scanf( "%d", &n );
  while ( n-- ) {
    scanf( "%d %d", &a, &b );
    printf( "%d\n", reverse( reverse( a ) + reverse( b ) ) );
  }

  return 0;
}
