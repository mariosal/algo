#include <cstdio>
#include <map>

using namespace std;

int main() {
  char i, j, s[ 101 ];
  short t;
  map< char, char > m;
  m[ 'y' ] = 'a';
  m[ 'n' ] = 'b';
  m[ 'f' ] = 'c';
  m[ 'i' ] = 'd';
  m[ 'c' ] = 'e';
  m[ 'w' ] = 'f';
  m[ 'l' ] = 'g';
  m[ 'b' ] = 'h';
  m[ 'k' ] = 'i';
  m[ 'u' ] = 'j';
  m[ 'o' ] = 'k';
  m[ 'm' ] = 'l';
  m[ 'x' ] = 'm';
  m[ 's' ] = 'n';
  m[ 'e' ] = 'o';
  m[ 'v' ] = 'p';
  m[ 'z' ] = 'q';
  m[ 'p' ] = 'r';
  m[ 'd' ] = 's';
  m[ 'r' ] = 't';
  m[ 'j' ] = 'u';
  m[ 'g' ] = 'v';
  m[ 't' ] = 'w';
  m[ 'h' ] = 'x';
  m[ 'a' ] = 'y';
  m[ 'q' ] = 'z';

  scanf( "%hd\n", &t );
  for ( i = 1; i <= t; ++i ) {
    gets( s );
    printf( "Case #%d: ", i );
    for ( j = 0; s[ j ]; ++j ) {
      if ( s[ j ] == ' ' ) {
        printf( " " );
      }
      else {
        printf( "%c", m[ s[ j ] ] );
      }
    }
    printf( "\n" );
  }

  return 0;
}
