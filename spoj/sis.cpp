#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main() {
  int i, j, k;
  long long sum, *w;
  set< int > s;
  vector< int > a;

  while ( scanf( "%d", &i ) != EOF ) {
    a.push_back( i );
  }

  w = new long long[ a.size() ];

  w[ 0 ] = 1;
  for ( i = 1; i < a.size(); ++i ) {
    w[ i ] = 1;
    s.clear();
    for ( j = i - 1; j >= 0; --j ) {
      if ( a[ j ] < a[ i ]  && s.find( a[ j ] ) == s.end() ) {
        w[ i ] += w[ j ];
        s.insert( a[ j ] );
      }
    }
  }

  sum = 0;
  s.clear();
  for ( i = a.size() - 1; i >= 0; --i ) {
    if ( s.find( a[ i ] ) == s.end() ) {
      sum += w[ i ] - 1;
      s.insert( a[ i ] );
    }
  }
  printf( "%d\n", sum );

  return 0;
}
