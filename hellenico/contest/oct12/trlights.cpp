#include <cstdio>

int main() {
  char i, j, red;

  freopen( "trlights.in", "r", stdin );
  freopen( "trlights.out", "w", stdout );

  red = 0;
  for ( i = 0; i < 10; ++i ) {
    scanf( "%c", &j );
    if ( j == 'r' ) {
      ++red;
    }
  }
  if ( red >= 5 ) {
    printf( "*\n" );
  }
  else if ( red % 2 ) {
    printf( "**\n" );
  }
  else if ( red == 0 ) {
    printf( "****\n" );
  }
  else if ( red % 2 == 0 ) {
    printf( "***\n" );
  }

  return 0;
}
