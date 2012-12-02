#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main() {
  short n, i, j;
  set< pair< short, short > > s;

  scanf( "%hd", &n );
  for ( i = 1; i <= n; ++i ) {
    for ( j = 1; i * j <= n; ++j ) {
      s.insert( make_pair( min( i, j ), max( i, j ) ) );
    }
  }
  printf( "%d\n", s.size() );

  return 0;
}
