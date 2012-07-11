#include <cstdio>

int main() {
  char i;
  float x, sum;

  sum = 0;
  for ( i = 0; i < 12; ++i ) {
    scanf( "%f", &x );
    sum += x;
  }
  printf( "$%.2f\n", sum / 12 );

  return 0;
}
