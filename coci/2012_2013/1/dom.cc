#include <cstdio>

bool contain( const char *s, char c ) {
  char i;
  for ( i = 0; s[ i ]; ++i ) {
    if ( c == s[ i ] ) {
      return true;
    }
  }
  return false;
}

int main() {
  const char *s = "CAMBRDIGE";
  char i, c;

  while ( scanf( "%c", &c ) != EOF ) {
    if ( !contain( s, c ) ) {
      printf( "%c", c );
    }
  }

  return 0;
}
