#include <cstdio>
#include <algorithm>

using namespace std;

struct Node {
  int maxSum, lSum, rSum;
};

void init( Node *heap, short *a, int *partial, int k, int s, int t ) {
  if ( s == t ) {
    heap[ k ] = ( Node ) {
      a[ s ], a[ s ], a[ s ]
    };
  }
  else {
    init( heap, a, partial, 2 * k, s, ( s + t ) / 2 );
    init( heap, a, partial, 2 * k + 1, ( s + t ) / 2 + 1, t );

    heap[ k ].maxSum = max( heap[ 2 * k ].maxSum, max( heap[ 2 * k + 1 ].maxSum, heap[ 2 * k ].rSum + heap[ 2 * k + 1 ].lSum ) );
    heap[ k ].lSum = max( heap[ 2 * k ].lSum, partial[ ( s + t ) / 2 ] - partial[ s - 1 ] + heap[ 2 * k + 1 ].lSum );
    heap[ k ].rSum = max( heap[ 2 * k + 1 ].rSum, partial[ t ] - partial[ ( s + t ) / 2 ] + heap[ 2 * k ].rSum );
  }
}
Node query( Node *heap, int *partial, int k, int s, int t, int i, int j ) {
  Node left, right;

  if ( s == i && t == j ) {
    return heap[ k ];
  }
  if ( j <= ( s + t ) / 2 ) {
    return query( heap, partial, 2 * k, s, ( s + t ) / 2, i, j );
  }
  if ( i > ( s + t ) / 2 ) {
    return query( heap, partial, 2 * k + 1, ( s + t ) / 2 + 1, t, i, j );
  }

  left = query( heap, partial, 2 * k, s, ( s + t ) / 2, i, ( s + t ) / 2 );
  right = query( heap, partial, 2 * k + 1, ( s + t ) / 2 + 1, t, ( s + t ) / 2 + 1, j );

  return ( Node ) {
    max( left.maxSum, max( right.maxSum, left.rSum + right.lSum ) ),
    max( left.lSum, partial[ ( s + t ) / 2 ] - partial[ s - 1 ] + right.lSum ),
    max( right.rSum, partial[ t ] - partial[ ( s + t ) / 2 ] + left.rSum )
  };
}

int main() {
  short *a;
  int n, m, i, j, *partial;
  Node *heap;

  scanf( "%d", &n );
  a = new short[ n ];
  partial = new int[ n ];
  heap = new Node[ 4 * n ];
  for ( i = 0; i < n; ++i ) {
    scanf( "%hd", &a[ i ] );
    if ( !i ) {
      partial[ i ] = 0;
    }
    else {
      partial[ i ] = partial[ i - 1 ];
    }
    partial[ i ] += a[ i ];
  }
  init( heap, a, partial, 1, 0, n - 1 );

  scanf( "%d", &m );
  while ( m-- ) {
    scanf( "%d %d", &i, &j );
    printf( "%d\n", query( heap, partial, 1, 0, n - 1, i - 1, j - 1 ).maxSum );
  }

  return 0;
}
