#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *s;
  int len;
} state;

state lcs( char *X, char *Y, int n, int m ) {
  char DIAG, UP, LEFT, **b;
  int i, j, **c;
  state answer;

  DIAG = 0;
  UP = 1;
  LEFT = 2;

  b = ( char** )malloc( ( n + 1 ) * sizeof( char* ) );
  c = ( int** )malloc( ( n + 1 ) * sizeof( int* ) );
  for ( i = 0; i <= n; i += 1 ) {
    b[ i ] = ( char* )malloc( m + 1 );
    c[ i ] = ( int* )malloc( ( m + 1 ) * sizeof( int ) );
  }

  for ( i = 1; i <= n; i += 1 ) {
    c[ i ][ 0 ] = 0;
    b[ i ][ 0 ] = UP;
  }
  for ( i = 0; i <= m; i += 1 ) {
    c[ 0 ][ i ] = 0;
    b[ 0 ][ i ] = LEFT;
  }

  for ( i = 1; i <= n; i += 1 ) {
    for ( j = 1; j <= m; j += 1 ) {
      if ( X[ i - 1 ] == Y[ j - 1 ] ) {
        c[ i ][ j ] = c[ i - 1 ][ j - 1 ] + 1;
        b[ i ][ j ] = DIAG;
      }
      else if ( c[ i - 1 ][ j ] >= c[ i ][ j - 1 ] ) {
        c[ i ][ j ] = c[ i - 1 ][ j ];
        b[ i ][ j ] = UP;
      }
      else {
        c[ i ][ j ] = c[ i ][ j - 1 ];
        b[ i ][ j ] = LEFT;
      }
    }
  }

  answer.len = c[ n ][ m ];
  answer.s = ( char* )malloc( c[ n ][ m ] + 1 );

  i = n;
  j = m;
  answer.s[ c[ i ][ j ] ] = '\0';
  while ( i != 0 && j != 0 ) {
    switch( b[ i ][ j ] ) {
      case 0:
        answer.s[ c[ i ][ j ] - 1 ] = X[ i - 1 ];
        i -= 1;
        j -= 1;
        break;
      case 1:
        i -= 1;
        break;
      case 2:
        j -= 1;
        break;
    }
  }

  return answer;
}

int main() {
  char X[ 30 ] = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
  char Y[ 29 ] = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
  state answer;

  answer = lcs( X, Y, 29, 28 );

  printf( "X: %s\n", X );
  printf( "Y: %s\n", Y );
  printf( "LCS: %s\n", answer.s );
  printf( "Length of LCS: %d\n", answer.len );

  return 0;
}
