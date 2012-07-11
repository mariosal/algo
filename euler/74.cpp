#include <cstdio>
#include <set>
#include <map>

using namespace std;

int factorial( char n ) {
  if ( !n ) {
    return 1;
  }
  return n * factorial( n - 1 );
}

int split( int n ) {
  int combined;

  combined = 0;
  while ( n ) {
    combined += factorial( n % 10 );
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
  for ( i = 0; i < 1000000; ++i ) {
    j = i;
    count = 0;
    while ( mark.insert( j ).second && count < 60 ) {
      ++count;
      j = split( j );

      it = memo.find( j );
      if ( it != memo.end() ) {
        count += it->second;
        break;
      }
    }
    memo[ i ] = count;

    if ( count == 60 ) {
      ++ans;
    }
    mark.clear();
  }
  printf( "%d\n", ans );

  return 0;
}
