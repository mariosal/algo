#include <cstdio>
#include <cstring>

char *reverse( char *s, char i, char j ) {
  char k, *t;

  t = new char[ j - i + 2 ];
  t[ j - i + 1 ] = '\0';
  for ( k = 0; k <= j - i; ++k ) {
    t[ k ] = s[ j - k ];
  }
  return t;
}

int main() {
  char i, n, last, a[ 51 ], best[ 51 ], *reversed;

  freopen( "lektira.in", "r", stdin );
  freopen( "lektira.out", "w", stdout );

  scanf( "%s", a );
  n = strlen( a );

  best[ 0 ] = a[ 0 ];
  best[ 1 ] = '\0';
  for ( i = 1; i < n - 2; ++i ) {
    reversed = reverse( a, 0, i );
    if ( strcmp( best, reversed ) > 0 ) {
      strcpy( best, reversed );
    }
  }
  last = strlen( best );
  printf( "%s", best );

  best[ 0 ] = a[ last ];
  best[ 1 ] = '\0';
  for ( i = last; i < n - 1; ++i ) {
    reversed = reverse( a, last, i );
    if ( strcmp( best, reversed ) > 0 ) {
      strcpy( best, reversed );
    }
  }
  last += strlen( best );
  printf( "%s", best );

  for ( i = n - 1; i >= last; --i ) {
    printf( "%c", a[ i ] );
  }
  printf( "\n" );

  return 0;
}
