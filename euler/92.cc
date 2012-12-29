#include <cstdio>
#include <set>
#include <map>

using namespace std;

int split( int n ) {
  int combined;

  combined = 0;
  while ( n ) {
    combined += ( n % 10 ) * ( n % 10 );
    n /= 10;
  }
  return combined;
}

int main() {
  int i, j, count, ans;
  set< int > mark;
  map< int, int > memo;
  map< int, int >::iterator it;

  ans = 0;
  for ( i = 0; i < 10000000; ++i ) {
    j = i;
    while ( mark.insert( j ).second && j != 89 ) {
      j = split( j );
      it = memo.find( j );
      if ( it != memo.end() ) {
        j = it->second;
        break;
      }
    }
    memo[ i ] = j;
    if ( memo[ i ] == 89 ) {
      ++ans;
    }

    mark.clear();
  }
  printf( "%d\n", ans );

  return 0;
}
