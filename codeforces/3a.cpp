#include <cstdio>
#include <string>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef struct {
  char x;
  char y;
} Point;

typedef struct {
  Point coords;
  int w;
  vector< string > bt;
} Node;

bool operator <( Point a, Point b ) {
  if ( a.x == b.x ) {
    return a.y < b.y;
  }
  return a.x < b.x;
}

void bfs( Point src, Point trg ) {
  char i;
  Node front;
  set< Point > mark;
  vector< string > dummy;
  queue< Node > q;

  q.push( ( Node ) {
    src,
    0
  } );
  while ( !q.empty() ) {
    front = q.front();
    q.pop();

    if ( !mark.insert( front.coords ).second ||
       front.coords.x < 1 || front.coords.x > 8 ||
       front.coords.y < 1 || front.coords.y > 8 ) {
      continue;
    }
    if ( front.coords.x == trg.x && front.coords.y == trg.y ) {
      printf( "%d\n", front.w );
      for ( i = 0; i < front.bt.size(); ++i ) {
        printf( "%s\n", front.bt[ i ].c_str() );
      }
      break;
    }

    dummy = front.bt;
    dummy.push_back( "R" );
    q.push( ( Node ) {
      ( Point ) {
        front.coords.x + 1,
        front.coords.y,
      },
      front.w + 1,
      dummy
    } );

    dummy = front.bt;
    dummy.push_back( "L" );
    q.push( ( Node ) {
      ( Point ) {
        front.coords.x - 1,
        front.coords.y,
      },
      front.w + 1,
      dummy
    } );

    dummy = front.bt;
    dummy.push_back( "U" );
    q.push( ( Node ) {
      ( Point ) {
        front.coords.x,
        front.coords.y + 1,
      },
      front.w + 1,
      dummy
    } );

    dummy = front.bt;
    dummy.push_back( "D" );
    q.push( ( Node ) {
      ( Point ) {
        front.coords.x,
        front.coords.y - 1,
      },
      front.w + 1,
      dummy
    } );

    dummy = front.bt;
    dummy.push_back( "RU" );
    q.push( ( Node ) {
      ( Point ) {
        front.coords.x + 1,
        front.coords.y + 1,
      },
      front.w + 1,
      dummy
    } );

    dummy = front.bt;
    dummy.push_back( "LU" );
    q.push( ( Node ) {
      ( Point ) {
        front.coords.x - 1,
        front.coords.y + 1,
      },
      front.w + 1,
      dummy
    } );

    dummy = front.bt;
    dummy.push_back( "RD" );
    q.push( ( Node ) {
      ( Point ) {
        front.coords.x + 1,
        front.coords.y - 1,
      },
      front.w + 1,
      dummy
    } );

    dummy = front.bt;
    dummy.push_back( "LD" );
    q.push( ( Node ) {
      ( Point ) {
        front.coords.x - 1,
        front.coords.y - 1,
      },
      front.w + 1,
      dummy
    } );
  }
}

int main() {
  char a[ 3 ], b[ 3 ];
  Point src, trg;

  scanf( "%s\n%s", a, b );
  src = ( Point ) {
    a[ 0 ] - 'a' + 1,
    a[ 1 ] - '0'
  };
  trg = ( Point ) {
    b[ 0 ] - 'a' + 1,
    b[ 1 ] - '0'
  };
  bfs( src, trg );

  return 0;
}
