#include <stdio.h>
#include <math.h>

int main() {
  const int lower_bound = sqrt( 1020304050607080900 );
  const int upper_bound = sqrt( 1929394959697989990 );
  int i;

  for ( i = lower_bound; i <= upper_bound; ++i ) {
    if (
      ( long long )i * i % 10 == 0 &&
      ( long long )i * i / 100 % 10 == 9 &&
      ( long long )i * i / 10000 % 10 == 8 &&
      ( long long )i * i / 1000000 % 10  == 7 &&
      ( long long )i * i / 100000000 % 10 == 6 &&
      ( long long )i * i / 10000000000 % 10 == 5 &&
      ( long long )i * i / 1000000000000 % 10 == 4 &&
      ( long long )i * i / 100000000000000 % 10 == 3 &&
      ( long long )i * i / 10000000000000000 % 10 == 2 &&
      ( long long )i * i / 1000000000000000000 % 10 == 1
    ) {
      printf( "%d\n", i );
      break;
    }
  }

  return 0;
}
