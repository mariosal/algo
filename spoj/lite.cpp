#include <cstdio>
#include <vector>

using namespace std;

struct Node {
  int all, on;
};
Node *heap;
vector< bool > flag;

void unflag( int k, int b, int e ) {
  if ( flag[ k ] ) {
    heap[ k ].on = heap[ k ].all - heap[ k ].on;
    flag[ k ] = false;
    if ( b != e ) {
      flag[ 2 * k ] = !flag[ 2 * k ];
      flag[ 2 * k + 1 ] = !flag[ 2 * k + 1 ];
    }
  }
}

void init( int k, int b, int e ) {
  if ( b == e ) {
    heap[ k ] = ( Node ) {
      1, 0
    };
  }
  else {
    init( 2 * k, b, ( b + e ) / 2 );
    init( 2 * k + 1, ( b + e ) / 2 + 1, e );

    heap[ k ] = ( Node ) {
      heap[ 2 * k ].all + heap[ 2 * k + 1 ].all, 0
    };
  }
}
void update( int i, int j, int k, int b, int e ) {
  if ( b > j || e < i ) {
    unflag( k, b, e );
  }
  else if ( b >= i && e <= j ) {
    flag[ k ] = !flag[ k ];
    unflag( k, b, e );
  }
  else {
    unflag( k, b, e );

    update( i, j, 2 * k, b, ( b + e ) / 2 );
    update( i, j, 2 * k + 1, ( b + e ) / 2 + 1, e );

    if ( b != e ) {
      heap[ k ].on = heap[ 2 * k ].on + heap[ 2 * k + 1 ].on;
    }
  }
}
int query( int i, int j, int k, int b, int e ) {
  if ( b > j || e < i ) {
    return 0;
  }

  unflag( k, b, e );
  if ( b >= i && e <= j ) {
    return heap[ k ].on;
  }
  else {
    return query( i, j, 2 * k, b, ( b + e ) / 2 ) + query( i, j, 2 * k + 1, ( b + e ) / 2 + 1, e );
  }
}

int main() {
  char cmd;
  int n, m, i, j;

  scanf( "%d %d\n", &n, &m );
  heap = new Node[ 4 * n ];
  flag.resize( 4 * n );
  init( 1, 1, n );

  while ( m-- ) {
    scanf( "%c %d %d\n", &cmd, &i, &j );
    switch ( cmd ) {
      case '0':
        update( i, j, 1, 1, n );
        break;
      case '1':
        printf( "%d\n", query( i, j, 1, 1, n ) );
        break;
    }
  }

  return 0;
}
