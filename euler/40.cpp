#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
  char *num, *buffer;
  int i, j, cntNum;

  num = new char[ 1000001 ];

  cntNum = 0;
  num[ 0 ] = '\0';
  for ( i = 1; cntNum < 1000000; ++i ) {
    buffer = new char[ ( int )log10( i ) + 2 ];
    sprintf( buffer, "%d", i );

    for ( j = 0; buffer[ j ]; ++j ) {
      if ( cntNum + j > 1000000 ) {
        break;
      }
      num[ cntNum + j ] = buffer[ j ];
    }
    cntNum += log10( i ) + 1;
    num[ cntNum ] = '\0';

    delete[] buffer;
  }
  printf( "%d\n", ( num[ 0 ] - '0' ) * ( num[ 9 ] - '0' ) * ( num[ 99 ] - '0' ) * ( num[ 999 ] - '0' ) * ( num[ 9999 ] - '0' ) * ( num[ 99999 ] - '0' ) * ( num[ 999999 ] - '0' ) );

  return 0;
}
