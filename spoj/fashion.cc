#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  short i, n, *a, *b;
  int t, ans;

  scanf( "%d", &t );
  while ( t-- ) {
    scanf( "%hd\n", &n );
    a = new short[ n ];
    b = new short[ n ];
    for ( i = 0; i < n; ++i ) {
      scanf( "%hd", a + i );
    }
    for ( i = 0; i < n; ++i ) {
      scanf( "%hd", b + i );
    }

    sort( a, a + n );
    sort( b, b + n );

    ans = 0;
    for ( i = 0; i < n; ++i ) {
      ans += a[ i ] * b[ i ];
    }
    printf( "%d\n", ans );

    delete[] a;
    delete[] b;
  }

  return 0;
}
