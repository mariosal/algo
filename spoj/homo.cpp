#include <cstdio>
#include <set>

using namespace std;

int main() {
  bool hetero;
  char cmd[ 7 ];
  int i, n, size, homo;
  multiset< int > s;

  homo = hetero = size = 0;
  scanf( "%d", &n );
  while ( n-- ) {
    scanf( "%s %d", cmd, &i );
    switch ( cmd[ 0 ] ) {
      case 'i':
        s.insert( i );
        switch( s.count( i ) ) {
          case 1:
            if ( ++size > 1 ) {
              hetero = true;
            }
            break;
          case 2:
            ++homo;
            break;
        }
        break;
      case 'd':
        if ( s.find( i ) != s.end() ) {
          s.erase( s.find( i ) );
          switch ( s.count( i ) ) {
            case 0:
              if ( --size <= 1 ) {
                hetero = false;
              }
              break;
            case 1:
              --homo;
              break;
          }
        }
        break;
    }

    if ( homo && hetero ) {
      printf( "both\n" );
    }
    else if ( homo ) {
      printf( "homo\n" );
    }
    else if ( hetero ) {
      printf( "hetero\n" );
    }
    else {
      printf( "neither\n" );
    }
  }

  return 0;
}
