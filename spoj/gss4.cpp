#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n, *root;
long long *bit;

void add( int k, long long v ) {
  while ( k <= n ) {
    bit[ k ] += v;
    k += k & -k;
  }
}
long long sum( int k ) {
  long long ret = 0;
  while ( k ) {
    ret += bit[ k ];
    k -= k & -k;
  }
  return ret;
}

int find( int i ) {
  if ( root[ i ] != i ) {
    root[ i ] = find( root[ i ] );
  }
  return root[ i ];
}
void update( int i, int j ) {
  int k = find( i );
  long long s, sq;
  while ( k <= j ) {
    s = sum( k ) - sum( k - 1 );
    if ( s != 1 ) {
      add( k, -s );
      sq = sqrt( s );
      add( k, sq );
      if ( sq == 1 ) {
        root[ k ] = k + 1;
      }
    }
    k = find( k + 1 );
  }
}

int main() {
  char cmd;
  int t, m, i, j;
  long long k;

  t = 1;
  while ( scanf( "%d", &n ) != EOF ) {
    bit = new long long[ n + 1 ];
    for ( i = 0; i <= n; ++i ) {
      bit[ i ] = 0;
    }

    root = new int[ n + 2 ];
    root[ n + 1 ] = n + 1;
    for ( i = 1; i <= n; ++i ) {
      scanf( "%lld", &k );
      root[ i ] = i;
      add( i, k );
    }

    printf( "Case #%d:\n", t++ );

    scanf( "%d", &m );
    while ( m-- ) {
      scanf( "\n%c %d %d", &cmd, &i, &j );
      if ( i > j ) {
        swap( i, j );
      }

      switch ( cmd ) {
        case '0':
          update( i, j );
          break;
        case '1':
          printf( "%lld\n", sum( j ) - sum( i - 1 ) );
          break;
      }
    }
    printf( "\n" );

    delete[] root;
    delete[] bit;
  }

  return 0;
}
