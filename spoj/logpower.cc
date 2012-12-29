#include <cstdio>

int power( int a, long long n, int m ) {
  int i;

  if ( n == 0 ) {
    return 1;
  }
  if ( n == 1 ) {
    return a % m;
  }
  i = power( a, n / 2, m );
  return ( ( ( long long )i * i ) % m * power( a, n % 2, m ) ) % m;
}

int main() {
  short t;
  int a, m;
  long long n;

  scanf( "%hd", &t );
  while ( t-- ) {
    scanf( "%d %lld %d", &a, &n, &m );
    printf( "%d\n", power( a, n, m ) );
  }

  return 0;
}
