#include <cstdio>
#include <set>

using namespace std;

int main() {
  int i, ans, n, k;
  set< int > s;
  set< int >::iterator it;

  scanf( "%d %d", &n, &k );
  while ( n-- ) {
    scanf( "%d", &i );
    s.insert( i );
  }

  ans = 0;
  for ( it = s.begin(); it != s.end(); ++it ) {
    ans += s.count( *it - k );
  }
  printf( "%d\n", ans );

  return 0;
}
