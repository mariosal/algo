#include <cstdio>
#include <climits>
#include <set>

using namespace std;

struct P {
  char x, y;
  short c;
};
bool operator <( P a, P b ) {
  if ( a.c == b.c ) {
    if ( a.x == b.x ) {
      return a.y < b.y;
    }
    return a.x < b.x;
  }
  return a.c < b.c;
}

short dijkstra( P s, P t ) {
  char i, j;
  short **w;
  set< P > q;

  w = new short*[ 8 ];
  for ( i = 0; i < 8; ++i ) {
    w[ i ] = new short[ 8 ];
    for ( j = 0; j < 8; ++j ) {
      w[ i ][ j ] = SHRT_MAX;
    }
  }

  q.insert( s );
  while ( !q.empty() ) {
    s = *q.begin();
    q.erase( *q.begin() );

    if ( s.x < 0 || s.x > 7 || s.y < 0 || s.y > 7 ) {
      continue;
    }
    if ( w[ s.x ][ s.y ] > s.c ) {
      w[ s.x ][ s.y ] = s.c;
      if ( s.x == t.x && s.y == t.y ) {
        break;
      }

      q.insert( ( P ) { s.x + 1, s.y + 2, s.c + s.x * ( s.x + 1 ) + s.y * ( s.y + 2 ) } );
      q.insert( ( P ) { s.x + 2, s.y + 1, s.c + s.x * ( s.x + 2 ) + s.y * ( s.y + 1 ) } );
      q.insert( ( P ) { s.x + 2, s.y - 1, s.c + s.x * ( s.x + 2 ) + s.y * ( s.y - 1 ) } );
      q.insert( ( P ) { s.x + 1, s.y - 2, s.c + s.x * ( s.x + 1 ) + s.y * ( s.y - 2 ) } );
      q.insert( ( P ) { s.x - 1, s.y - 2, s.c + s.x * ( s.x - 1 ) + s.y * ( s.y - 2 ) } );
      q.insert( ( P ) { s.x - 2, s.y - 1, s.c + s.x * ( s.x - 2 ) + s.y * ( s.y - 1 ) } );
      q.insert( ( P ) { s.x - 2, s.y + 1, s.c + s.x * ( s.x - 2 ) + s.y * ( s.y + 1 ) } );
      q.insert( ( P ) { s.x - 1, s.y + 2, s.c + s.x * ( s.x - 1 ) + s.y * ( s.y + 2 ) } );
    }
  }

  return w[ t.x ][ t.y ] == SHRT_MAX ? -1 : w[ t.x ][ t.y ];
}

int main() {
  char x1, y1, x2, y2;

  while ( scanf( "%c %c %c %c\n", &x1, &y1, &x2, &y2 ) != EOF ) {
    printf( "%hd\n", dijkstra(
      ( P ) { x1 - '0', y1 - '0' },
      ( P ) { x2 - '0', y2 - '0' }
    ) );
  }

  return 0;
}
