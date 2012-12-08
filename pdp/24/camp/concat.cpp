#include <cstdio>
#include <cstring>
#include <bitset>
#include <map>

using namespace std;

struct Trie  {
  int children[ 26 ];
};
bitset< 1000 * 1000 + 1 > word;
Trie *T = new Trie[ 1000 * 1000 + 1 ];
int cnt;

void add( char *s ) {
  int i, j, cur;

  cur = 0;
  for ( i = 0; s[ i ]; ++i ) {
    j = T[ cur ].children[ s[ i ] - 'a' ];
    if ( !j ) {
      ++cnt;
      T[ cur ].children[ s[ i ] - 'a' ] = cnt;
      cur = cnt;
    }
    else {
      cur = j;
    }
  }
  word[ cur ] = true;
}
void cmp( char *s, long long *w ) {
  int i, j, cur;

  cur = 0;
  w[ 0 ] = 0;
  for ( i = 0; s[ i ]; ++i ) {
    j = T[ cur ].children[ s[ i ] - 'a' ];
    if ( !j ) {
      break;
    }
    else {
      cur = j;
      if ( word[ cur ] ) {
        w[ 0 ] = ( w[ 0 ] + w[ i + 1 ] ) % 3141592653589793;
      }
    }
  }
}

int main() {
  char *s = new char[ 1000001 ];
  int i, n;
  long long *w;

  scanf( "%hd", &n );
  for ( i = 0; i < n; ++i ) {
    scanf( "%s", s );
    add( s );
  }

  scanf( "%s", s );
  n = strlen( s );
  w = new long long[ n + 1 ];
  w[ n ] = 1;
  for ( i = n - 1; i >= 0; --i ) {
    cmp( s + i, w + i );
  }
  printf( "%lld\n", w[ 0 ] );

  return 0;
}
