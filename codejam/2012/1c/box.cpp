#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

typedef pair< pair< char, char >, pair< long, long > > state;

typedef struct {
  long amount;
  short type;
} item;

long rdp( item *box, char cntBox, item *toy, char cntToy, char i, char j, long takeI, long takeJ ) {
  long ans;
  state key;
  static map< state, long > memo;
  map< state, long >::iterator it;

  if ( i >= cntBox || j >= cntToy ) {
    return 0;
  }

  key = make_pair( make_pair( i, j ), make_pair( takeI, takeJ ) );
  it = memo.find( key );
  if ( it != memo.end() ) {
    return it->second;
  }

  if ( box[ i ].type == toy[ j ].type ) {
    if ( box[ i ].amount - takeI > toy[ j ].amount - takeJ ) {
      ans = toy[ j ].amount - takeJ + rdp( box, cntBox, toy, cntToy, i, j + 1, takeI + toy[ j ].amount - takeJ, 0 );
    }
    else {
      ans = box[ i ].amount - takeI + rdp( box, cntBox, toy, cntToy, i + 1, j, 0, takeJ + box[ i ].amount - takeI );
    }
  }
  else {
    ans = max(
      rdp( box, cntBox, toy, cntToy, i + 1, j, 0, takeJ ),
      rdp( box, cntBox, toy, cntToy, i, j + 1, takeI, 0 )
    );
  }

  if ( !i && !j ) {
    memo.clear();
    return ans;
  }
  return memo[ key ] = ans;
}

int main() {
  short t, i, j, cntBox, cntToy;
  item *box, *toy;

  scanf( "%hd", &t );
  for ( i = 1; i <= t; ++i ) {
    scanf( "%hd %hd", &cntBox, &cntToy );
    box = new item[ cntBox ];
    toy = new item[ cntToy ];

    for ( j = 0; j < cntBox; ++j ) {
      scanf( "%ld %hd", &box[ j ].amount, &box[ j ].type );
    }
    for ( j = 0; j < cntToy; ++j ) {
      scanf( "%ld %hd", &toy[ j ].amount, &toy[ j ].type );
    }
    printf( "Case #%hd: %ld\n", i, rdp( box, cntBox, toy, cntToy, 0, 0, 0, 0 ) );

    delete[] box;
    delete[] toy;
  }

  return 0;
}
