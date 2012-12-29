#include <cstdio>

long long *heap, *flag;

void unflag( int k, int b, int e ) {
  if ( flag[ k ] ) {
    heap[ k ] += ( e - b + 1 ) * flag[ k ];
    if ( b != e ) {
      flag[ 2 * k ] += flag[ k ];
      flag[ 2 * k + 1 ] += flag[ k ];
    }
    flag[ k ] = 0;
  }
}
void update( int i, int j, int k, int b, int e, int v ) {
  if ( b > j || e < i ) {
    unflag( k, b, e );
  }
  else if ( b >= i && e <= j ) {
    flag[ k ] += v;
    unflag( k, b, e );
  }
  else {
    unflag( k, b, e );

    update( i, j, 2 * k, b, ( b + e ) / 2, v );
    update( i, j, 2 * k + 1, ( b + e ) / 2 + 1, e, v );

    if ( b != e ) {
      heap[ k ] = heap[ 2 * k ] + heap[ 2 * k + 1 ];
    }
  }
}
long long query( int i, int j, int k, int b, int e ) {
  if ( b > j || e < i ) {
    return 0;
  }

  unflag( k, b, e );
  if ( b >= i && e <= j ) {
    return heap[ k ];
  }
  else {
    return query( i, j, 2 * k, b, ( b + e ) / 2 ) + query( i, j, 2 * k + 1, ( b + e ) / 2 + 1, e );
  }
}

int main() {
  char cmd[ 13 ];
  short t, k;
  int n, m, i, j, v;

  scanf( "%hd", &t );
  for ( k = 1; k <= t; ++k ) {
    scanf( "%d %d", &n, &m );

    heap = new long long[ 4 * n ];
    flag = new long long[ 4 * n ];
    for ( i = 0; i < 4 * n; ++i ) {
      heap[ i ] = 0;
      flag[ i ] = 0;
    }

    printf( "Scenario #%hd:\n", k );
    while ( m-- ) {
      scanf( "%s %d %d", cmd, &i, &j );
      switch ( cmd[ 0 ] ) {
        case 'm':
          update( i, j, 1, 1, n, 1 );
          printf( "OK\n" );
          break;
        case 'a':
          printf( "%lld\n", query( i, j, 1, 1, n ) );
          break;
      }
    }

    delete[] heap;
    delete[] flag;
  }

  return 0;
}
