#include <cstdio>
#include <map>

using namespace std;

map< long long, long long > m;
long long strength( long long n ) {
  long long i, ans;
  map< long long, long long >::iterator it;

  if ( n == 2 ) {
    return 1;
  }

  for ( i = 2; i < n; ++i ) {
    if ( n % i ) {
      it = m.find( i );
      if ( it != m.end() ) {
        ans = 1 + it->second;
      }
      else {
        ans = 1 + strength( i );
      }
      return m[ n ] = ans;
    }
  }
}

int main() {
  long long a, b, ans;

  scanf( "%lld %lld", &a, &b );
  ans = 0;
  for ( ; a <= b; ++a ) {
    ans += strength( a );
  }
  printf( "%lld\n", ans );

  return 0;
}
