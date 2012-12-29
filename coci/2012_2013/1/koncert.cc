#include <cstdio>
#include <set>

using namespace std;

int main() {
  int i, j, m, n, a, b;
  set< int > guT, gu, giT;
  set< int >::iterator it1, it2, tit1, tit2;

  scanf( "%d %d", &m, &a );
  for ( i = 0; i < m; ++i ) {
    gu.insert( i + 1 );
  }
  for ( i = 0; i < a; ++i ) {
    scanf( "%d", &j );
    guT.insert( j );
    gu.erase( j );
  }

  scanf( "%d %d", &n, &b );
  for ( i = 0; i < b; ++i ) {
    scanf( "%d", &j );
    giT.insert( j );
  }

  for ( it1 = gu.begin(), it2 = giT.begin(); it1 != gu.end() && it2 != giT.end(); ) {
    printf( "GIVE GIRL %d GUY %d\n", *it2, *it1 );
    tit1 = it1;
    tit2 = it2;
    ++it1;
    ++it2;
    guT.insert( *tit1 );
    gu.erase( tit1 );
    giT.erase( tit2 );
  }
  for ( it1 = guT.begin(); it1 != guT.end(); ++it1 ) {
    printf( "ENTER GUY %d\n", *it1 );
  }
  if ( gu.size() ) {
    for ( it1 = guT.begin(), ++it1, it2 = gu.begin(); it1 != guT.end() && it2 != gu.end(); ++it1, ++it2 ) {
      printf( "GIVE GUY %d GUY %d\n", *it1, *guT.begin() );
    }
    printf( "EXIT GUY %d\n", *guT.begin() );
    for ( it1 != gu.begin(); it1 != gu.end(); ++it1 ) {
      printf( "ENTER GUY %d\n", *it1 );
    }
  }

  return 0;
}
