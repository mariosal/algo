#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

map< unsigned, unsigned > w;
void memo( unsigned n ) {
  if ( w.find( n ) != w.end() ) {
    return;
  }

  memo( n / 2 );
  memo( n / 3 );
  memo( n / 4 );
  w[ n ] = max( n, w[ n / 2 ] + w[ n / 3 ] + w[ n / 4 ] );
}

int main() {
  unsigned n;

  w[ 0 ] = 0;
  while ( scanf( "%u", &n ) != EOF ) {
    memo( n );
    printf( "%u\n", w[ n ] );
  }

  return 0;
}
