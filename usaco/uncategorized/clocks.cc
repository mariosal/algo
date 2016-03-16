/*
  PROG: clocks
  ID: mariosa1
  LANG: C++
*/
#include <cstdio>
#include <vector>

using namespace std;

vector< char > printify( const char *a ) {
  char i, j;
  vector< char > ret;

  for ( i = 0; i < 9; ++i ) {
    for ( j = a[ i ]; j > 0; --j ) {
      ret.push_back( i + 1 );
    }
  }

  return ret;
}
bool check( const char *a, const char *clocks ) {
  char i, cp[ 9 ];

  for ( i = 0; i < 9; ++i ) {
    cp[ i ] = clocks[ i ];
  }

  cp[ 0 ] = ( cp[ 0 ] + 3 * a[ 0 ] + 3 * a[ 1 ] + 3 * a[ 3 ] ) % 12;
  cp[ 1 ] = ( cp[ 1 ] + 3 * a[ 0 ] + 3 * a[ 1 ] + 3 * a[ 2 ] + 3 * a[ 4 ] ) % 12;
  cp[ 2 ] = ( cp[ 2 ] + 3 * a[ 1 ] + 3 * a[ 2 ] + 3 * a[ 5 ] ) % 12;
  cp[ 3 ] = ( cp[ 3 ] + 3 * a[ 0 ] + 3 * a[ 3 ] + 3 * a[ 4 ] + 3 * a[ 6 ] ) % 12;
  cp[ 4 ] = ( cp[ 4 ] + 3 * a[ 0 ] + 3 * a[ 2 ] + 3 * a[ 4 ] + 3 * a[ 6 ] + 3 * a[ 8 ] ) % 12;
  cp[ 5 ] = ( cp[ 5 ] + 3 * a[ 2 ] + 3 * a[ 4 ] + 3 * a[ 5 ] + 3 * a[ 8 ] ) % 12;
  cp[ 6 ] = ( cp[ 6 ] + 3 * a[ 3 ] + 3 * a[ 6 ] + 3 * a[ 7 ] ) % 12;
  cp[ 7 ] = ( cp[ 7 ] + 3 * a[ 4 ] + 3 * a[ 6 ] + 3 * a[ 7 ] + 3 * a[ 8 ] ) % 12;
  cp[ 8 ] = ( cp[ 8 ] + 3 * a[ 5 ] + 3 * a[ 7 ] + 3 * a[ 8 ] ) % 12;

  for ( i = 0; i < 9; ++i ) {
    if ( cp[ i ] ) {
      return false;
    }
  }
  return true;
}

int main() {
  char i, j, sol[ 9 ], clocks[ 9 ];
  short dummy;
  vector< char > possible, best( 27 );

  freopen( "clocks.in", "r", stdin );
  freopen( "clocks.out", "w", stdout );

  for ( i = 0; i < 9; ++i ) {
    scanf( "%hd", &dummy );
    clocks[ i ] = dummy;
  }

  for ( sol[ 0 ] = 0; sol[ 0 ] < 4; ++sol[ 0 ] ) {
    for ( sol[ 1 ] = 0; sol[ 1 ] < 4; ++sol[ 1 ] ) {
      for ( sol[ 2 ] = 0; sol[ 2 ] < 4; ++sol[ 2 ] ) {
        for ( sol[ 3 ] = 0; sol[ 3 ] < 4; ++sol[ 3 ] ) {
          for ( sol[ 4 ] = 0; sol[ 4 ] < 4; ++sol[ 4 ] ) {
            for ( sol[ 5 ] = 0; sol[ 5 ] < 4; ++sol[ 5 ] ) {
              for ( sol[ 6 ] = 0; sol[ 6 ] < 4; ++sol[ 6 ] ) {
                for ( sol[ 7 ] = 0; sol[ 7 ] < 4; ++sol[ 7 ] ) {
                  for ( sol[ 8 ] = 0; sol[ 8 ] < 4; ++sol[ 8 ] ) {
                    if ( check( sol, clocks ) ) {
                      possible = printify( sol );
                      if ( possible.size() <= best.size() ) {
                        best = possible;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  for ( i = 0; i < best.size(); ++i ) {
    printf( "%s%d", i ? " " : "", best[ i ] );
  }
  printf( "\n" );

  return 0;
}
