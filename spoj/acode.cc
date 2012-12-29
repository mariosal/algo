#include <cstdio>
#include <cstring>

using namespace std;

char s[ 5001 ];
short n;
long long *w;

short ati( short i, short j ) {
  short ret = 0;
  for ( ; i <= j; ++i ) {
    ret *= 10;
    ret += s[ i ] - '0';
  }
  return ret;
}

void memo( short i ) {
  if ( i >= n ) {
    return;
  }
  if ( w[ i ] || s[ i ] == '0' ) {
    return;
  }

  for ( short j = i; j < n && ati( i, j ) <= 26; ++j ) {
    memo( j + 1 );
    w[ i ] += w[ j + 1 ];
  }
}

int main() {
  short i;

  while ( 1 ) {
    scanf( "%s", s );
    if ( s[ 0 ] == '0' ) {
      break;
    }

    n = strlen( s );
    w = new long long[ n + 1 ];

    for ( i = 0; i <= n; ++i ) {
      w[ i ] = 0;
    }
    w[ n ] = 1;
    memo( 0 );
    printf( "%lld\n", w[ 0 ] );

    delete[] w;
  }

  return 0;
}
