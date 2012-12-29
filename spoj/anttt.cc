#include <cstdio>

struct Point {
  short x, y;
};
struct Line {
  Point s, e;
};

struct Disjoint {
  short parent, rank;
};
Disjoint *sets;
short find( short a ) {
  if ( sets[ a ].parent != a ) {
    sets[ a ].parent = find( sets[ a ].parent );
  }
  return sets[ a ].parent;
}
void unite( short a, short b ) {
  a = find( a );
  b = find( b );
  if ( a == b ) {
    return;
  }

  if ( sets[ a ].rank > sets[ b ].rank ) {
    sets[ b ].parent = a;
  }
  else {
    sets[ a ].parent = b;
    if ( sets[ a ].rank == sets[ b ].rank ) {
      ++sets[ b ].rank;
    }
  }
}

long long ccw( Point a, Point b, Point c ) {
  return ( long long )( b.x - a.x ) * ( c.y - a.y ) - ( b.y - a.y ) * ( c.x - a.x );
}
bool middle( short a, short b, short c) {
  if ( a > b ) {
    return middle( b, a, c );
  }
  if ( a <= c && c <= b ) {
    return true;
  }
  return false;
}
bool intersect( Line a, Line b ) {
  if ( ccw( a.s, a.e, b.s ) * ccw( a.s, a.e, b.e ) < 0 &&
       ccw( b.s, b.e, a.s ) * ccw( b.s, b.e, a.e ) < 0 ) {
    return true;
  }

  if ( !ccw( a.s, a.e, b.s ) && middle( a.s.x, a.e.x, b.s.x ) && middle( a.s.y, a.e.y, b.s.y ) ) {
    return true;
  }
  if ( !ccw( a.s, a.e, b.e ) && middle( a.s.x, a.e.x, b.e.x ) && middle( a.s.y, a.e.y, b.e.y ) ) {
    return true;
  }
  if ( !ccw( b.s, b.e, a.s ) && middle( b.s.x, b.e.x, a.s.x ) && middle( b.s.y, b.e.y, a.s.y ) ) {
    return true;
  }
  if ( !ccw( b.s, b.e, a.e ) && middle( b.s.x, b.e.x, a.e.x ) && middle( b.s.y, b.e.y, a.e.y ) ) {
    return true;
  }
  return false;
}

int main() {
  short i, j, k, n, m, t;
  Line *lines;

  scanf( "%hd", &t );
  while ( t-- ) {
    scanf( "%hd %hd", &n, &m );
    lines = new Line[ n ];
    sets = new Disjoint[ n ];

    for ( i = 0; i < n; ++i ) {
      scanf( "%hd %hd %hd %hd", &lines[ i ].s.x, &lines[ i ].s.y, &lines[ i ].e.x, &lines[ i ].e.y );
      sets[ i ] = ( Disjoint ) {
        i, 0
      };
    }

    for ( i = 0; i < n; ++i ) {
      for ( j = i + 1; j < n; ++j ) {
        if ( intersect( lines[ i ], lines[ j ] ) ) {
          unite( i, j );
        }
      }
    }

    for ( i = 0; i < m; ++i ) {
      scanf( "%hd %hd", &j, &k );
      --j;
      --k;

      if ( find( j ) == find( k ) ) {
        printf( "YES\n" );
      }
      else {
        printf( "NO\n" );
      }
    }

    delete[] lines;
    delete[] sets;
  }

  return 0;
}
