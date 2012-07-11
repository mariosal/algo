#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int toi( char *a, char from, char to ) {
  int n;

  n = 0;
  while ( from <= to ) {
    n *= 10;
    n += a[ from ];
    ++from;
  }

  return n;
}

int main() {
  char i, j, a[ 9 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  unsigned short ans;
  int multiplicand, multiplier, product;
  set< int > mark;

  ans = 0;
  do {
    for ( i = 0; i <= 6; ++i ) {
      for ( j = i + 1; j <= 7; ++j ) {
        multiplicand = toi( a, 0, i );
        multiplier = toi( a, i + 1, j );
        product = toi( a, j + 1, 8 );

        if ( multiplicand * multiplier == product ) {
          if ( mark.insert( product ).second ) {
            ans += product;
          }
        }
      }
    }
  } while ( next_permutation( a, a + 9 ) );
  printf( "%hu\n", ans );

  return 0;
}
