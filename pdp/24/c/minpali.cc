#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  char *s;
  int i, j, n, *pi;

  scanf( "%d", &n );
  s = new char[ 2 * n + 1 ];
  scanf( "%s", s + n );
  for ( i = 0; i < n; ++i ) {
    s[ i ] = s[ 2 * n - 1 - i ];
  }

  pi = new int[ 2 * n + 1 ];
  pi[ 0 ] = -1;
  j = -1;
  for ( i = 1; i <= 2 * n; ++i ) {
    while ( j >= 0 && s[ j ] != s[ i - 1 ] ) {
      j = pi[ j ];
    }
    pi[ i ] = ++j;
  }
  printf( "%d\n", 2 * n - min( n, pi[ 2 * n ] ) );

  return 0;
}
