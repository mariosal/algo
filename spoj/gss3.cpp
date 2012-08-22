#include <cstdio>
#include <algorithm>

using namespace std;

struct Node {
  int maxSum, lSum, rSum;
};
int n, *bit;
Node *heap;

void add( int pos, int val ) {
  while ( pos <= n ) {
    bit[ pos ] += val;
    pos += pos & -pos;
  }
}
int sum( int pos ) {
  int ret = 0;
  while ( pos ) {
    ret += bit[ pos ];
    pos -= pos & -pos;
  }
  return ret;
}

void init( int k, int s, int t ) {
  int val;

  if ( s == t ) {
    val = sum( s ) - sum( s - 1 );
    heap[ k ] = ( Node ) {
      val, val, val
    };
  }
  else {
    init( 2 * k, s, ( s + t ) / 2 );
    init( 2 * k + 1, ( s + t ) / 2 + 1, t );

    heap[ k ] = ( Node ) {
      max( heap[ 2 * k ].maxSum, max( heap[ 2 * k + 1 ].maxSum, heap[ 2 * k ].rSum + heap[ 2 * k + 1 ].lSum ) ),
      max( heap[ 2 * k ].lSum, sum( ( s + t ) / 2 ) - sum( s - 1 ) + heap[ 2 * k + 1 ].lSum ),
      max( heap[ 2 * k + 1 ].rSum, sum( t ) - sum( ( s + t ) / 2 ) + heap[ 2 * k ].rSum )
    };
  }
}
Node query( int k, int s, int t, int i, int j ) {
  Node l, r;

  if ( s == i && t == j ) {
    return heap[ k ];
  }
  if ( j <= ( s + t ) / 2 ) {
    return query( 2 * k, s, ( s + t ) / 2, i, j );
  }
  if ( i > ( s + t ) / 2 ) {
    return query( 2 * k + 1, ( s + t ) / 2 + 1, t, i, j );
  }

  l = query( 2 * k, s, ( s + t ) / 2, i, ( s + t ) / 2 );
  r = query( 2 * k + 1, ( s + t ) / 2 + 1, t, ( s + t ) / 2 + 1, j );

  return ( Node ) {
    max( l.maxSum, max( r.maxSum, l.rSum + r.lSum ) ),
    max( l.lSum, sum( ( s + t ) / 2 ) - sum( s - 1 ) + r.lSum ),
    max( r.rSum, sum( t ) - sum( ( s + t ) / 2 ) + l.rSum )
  };
}
void update( int k, int s, int t, int pos, int val ) {
  if ( s == t ) {
    add( pos, val - sum( s ) + sum( s - 1 ) );
    heap[ k ] = ( Node ) {
      val, val, val
    };
  }
  else {
    if ( pos <= ( s + t ) / 2 ) {
      update( 2 * k, s, ( s + t ) / 2, pos, val );
    }
    else {
      update( 2 * k + 1, ( s + t ) / 2 + 1, t, pos, val );
    }

    heap[ k ] = ( Node ) {
      max( heap[ 2 * k ].maxSum, max( heap[ 2 * k + 1 ].maxSum, heap[ 2 * k ].rSum + heap[ 2 * k + 1 ].lSum ) ),
      max( heap[ 2 * k ].lSum, sum( ( s + t ) / 2 ) - sum( s - 1 ) + heap[ 2 * k + 1 ].lSum ),
      max( heap[ 2 * k + 1 ].rSum, sum( t ) - sum( ( s + t ) / 2 ) + heap[ 2 * k ].rSum )
    };
  }
}

int main() {
  char op;
  int m, i, j;

  scanf( "%d", &n );

  bit = new int[ n + 1 ];
  for ( i = 0; i <= n; ++i ) {
    bit[ i ] = 0;
  }

  for ( i = 1; i <= n; ++i ) {
    scanf( "%d", &j );
    add( i, j );
  }

  heap = new Node[ 4 * n ];
  init( 1, 1, n );

  scanf( "%d\n", &m );
  while ( m-- ) {
    scanf( "%c %d %d\n", &op, &i, &j );
    switch ( op ) {
      case '0':
        update( 1, 1, n, i, j );
        break;
      case '1':
        printf( "%d\n", query( 1, 1, n, i, j ).maxSum );
        break;
    }
  }

  return 0;
}
