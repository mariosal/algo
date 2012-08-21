#include <cstdio>
#include <map>

using namespace std;

typedef pair< int, int > ii;

void init( ii *heap, int *a, int k, int s, int t ) {
  if ( s == t ) {
    heap[ k ] = make_pair( a[ s - 1 ], 0 );
  }
  else {
    init( heap, a, 2 * k, s, ( s + t ) / 2 );
    init( heap, a, 2 * k + 1, ( s + t ) / 2 + 1, t );

    heap[ k ].first = max( heap[ 2 * k ].first, heap[ 2 * k + 1 ].first );
    if ( heap[ k ].first == heap[ 2 * k ].first ) {
      heap[ k ].second = max( heap[ 2 * k ].second, heap[ 2 * k + 1 ].first );
    }
    else {
      heap[ k ].second = max( heap[ 2 * k ].first, heap[ 2 * k + 1 ].second );
    }
  }
}
ii query( ii *heap, int k, int s, int t, int i, int j ) {
  ii l, r, ans;

  if ( s == i && t == j ) {
    return heap[ k ];
  }
  if ( j <= ( s + t ) / 2 ) {
    return query( heap, 2 * k, s, ( s + t ) / 2, i, j );
  }
  if ( i > ( s + t ) / 2 ) {
    return query( heap, 2 * k + 1, ( s + t ) / 2 + 1, t, i, j );
  }

  l = query( heap, 2 * k, s, ( s + t ) / 2, i, ( s + t ) / 2 );
  r = query( heap, 2 * k + 1, ( s + t ) / 2 + 1, t, ( s + t ) / 2 + 1, j );

  ans.first = max( l.first, r.first );
  if ( ans.first == l.first ) {
    ans.second = max( l.second, r.first );
  }
  else {
    ans.second = max( l.first, r.second );
  }
  return ans;
}
void update( ii *heap, int k, int s, int t, int pos, int val ) {
  if ( s == t && s == pos ) {
    heap[ k ] = make_pair( val, 0 );
  }
  else {
    if ( pos <= ( s + t ) / 2 ) {
      update( heap, 2 * k, s, ( s + t ) / 2, pos, val );
    }
    else {
      update( heap, 2 * k + 1, ( s + t ) / 2 + 1, t, pos, val );
    }

    heap[ k ].first = max( heap[ 2 * k ].first, heap[ 2 * k + 1 ].first );
    if ( heap[ k ].first == heap[ 2 * k ].first ) {
      heap[ k ].second = max( heap[ 2 * k ].second, heap[ 2 * k + 1 ].first );
    }
    else {
      heap[ k ].second = max( heap[ 2 * k ].first, heap[ 2 * k + 1 ].second );
    }
  }
}

int main() {
  char op;
  int i, j, n, q, *a;
  ii ans, *heap;

  scanf( "%d", &n );
  a = new int[ n ];
  heap = new ii[ 4 * n ];
  for ( i = 0; i < n; ++i ) {
    scanf( "%d", &a[ i ] );
  }

  init( heap, a, 1, 1, n );
  scanf( "%d\n", &q );
  while ( q-- ) {
    scanf( "%c %d %d\n", &op, &i, &j );
    switch ( op ) {
      case 'Q':
        ans = query( heap, 1, 1, n, i, j );
        printf( "%d\n", ans.first + ans.second );
        break;
      case 'U':
        update( heap, 1, 1, n, i, j );
        break;
    }
  }

  return 0;
}
