#include <stdio.h>

int main() {
  short i;
  int t, n, sum;

  //freopen( "in.txt", "r", stdin );

  scanf( "%d", &t );
  while ( t-- ) {
    scanf( "%d", &n );

    for ( i = 2, sum = 1; i * i <= n; ++i ) {
      if ( n % i == 0 ) {
        sum += i;

        if ( n / i != i ) {
          sum += n / i;
        }
      }
    }

    if ( n == 1 ) {
      puts( "0" );
    }
    else {
      printf( "%d\n", sum );
    }
  }

  return 0;
}
