#include <stdio.h>
#include <string.h>

char hash( char *key ) {
  char i;
  short sum = 0;

  for ( i = 0; key[ i ]; ++i ) {
    sum += key[ i ] * ( i + 1 );
  }

  return 19 * sum % 101;
}

int main() {
  char j, q, size, hashkey, newhash, operation[ 4 ], key[ 16 ], table[ 101 ][ 16 ];
  short t, n, i;

  //freopen( "in.txt", "r", stdin );

  scanf( "%hd", &t );
  while ( t-- ) {
    size = 0;
    for ( j = 0; j < 101; ++j ) {
      table[ j ][ 0 ] = 0;
    }

    scanf( "%hd", &n );
    for ( i = 0; i < n; ++i ) {
      scanf( "%3s:%s", operation, key );

      hashkey = hash( key );
      for ( j = 0; j < 20; ++j ) {
        newhash = ( hashkey + j * j + 23 * j ) % 101;
        if ( !strcmp( operation, "ADD" ) ) {
          for ( q = 0; q < 101; ++q ) {
            if ( !strcmp( table[ q ], key ) ) {
              break;
            }
          }
          if ( q != 101 ) {
            break;
          }
          if ( !table[ newhash ][ 0 ] ) {
            strcpy( table[ newhash ], key );
            ++size;
            break;
          }
        }
        else if ( !strcmp( table[ newhash ], key ) ) {
          table[ newhash ][ 0 ] = 0;
          --size;
          break;
        }
      }
    }

    printf( "%d\n", size );
    for ( j = 0; j < 101; ++j ) {
      if ( table[ j ][ 0 ] ) {
        printf( "%d:%s\n", j, table[ j ] );
      }
    }
  }

  return 0;
}
