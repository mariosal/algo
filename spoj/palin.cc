#include <cstdio>
#include <cstring>

char *reverse( const char *s, int n ) {
  char *t;
  int i;

  t = new char[ n + 1 ];
  t[ n ] = '\0';
  for ( i = 0; i < n; ++i ) {
    t[ i ] = s[ n - i - 1 ];
  }
  return t;
}

char *inc( const char *s, int n ) {
  bool carry;
  char *t, *u;
  int i;

  t = new char[ n + 1 ];
  carry = true;
  for ( i = n - 1; i >= 0; --i ) {
    if ( carry && s[ i ] == '9' ) {
      t[ i ] = '0';
    }
    else {
      t[ i ] = s[ i ] + carry;
      carry = false;
    }
  }
  t[ n ] = '\0';

  if ( carry ) {
    u = new char[ n + 2 ];
    u[ 0 ] = '1';
    u[ 1 ] = '\0';
    strcat( u, t );

    return u;
  }
  return t;
}

int main() {
  char s[ 1000001 ], *ans, *half;
  int t, n;

  scanf( "%d", &t );
  while ( t-- ) {
    scanf( "%s", s );
    n = strlen( s );

    half = new char[ n / 2 + n % 2 + 1 ];
    strncpy( half, s, n / 2 + n % 2 );
    half[ n / 2 + n % 2 ] = '\0';

    ans = new char[ n + 3 ];
    strcpy( ans, half );
    strcat( ans, reverse( half, n / 2 ) );

    if ( strcmp( ans, s ) <= 0 ) {
      strcpy( ans, inc( half, n / 2 + n % 2 ) );
      strcat( ans, reverse( ans, n / 2 ) );
    }
    printf( "%s\n", ans );
  }

  return 0;
}
