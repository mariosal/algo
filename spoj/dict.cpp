#include <cstdio>
#include <string>
#include <map>

using namespace std;

struct Trie {
  bool word;
  map< char, int > children;
};

void add( Trie *T, int &size, char *s ) {
  char i;
  int cur;
  map< char, int >::iterator it;

  cur = 0;
  for ( i = 0; s[ i ]; ++i ) {
    it = T[ cur ].children.find( s[ i ] );
    if ( it == T[ cur ].children.end() ) {
      ++size;
      T[ cur ].children[ s[ i ] ] = size;
      cur = size;
    }
    else {
      cur = it->second;
    }
  }
  T[ cur ].word = true;
}

int check( Trie *T, char *s ) {
  char i;
  int cur;
  map< char, int >::iterator it;

  cur = 0;
  for ( i = 0; s[ i ]; ++i ) {
    it = T[ cur ].children.find( s[ i ] );
    if ( it == T[ cur ].children.end() ) {
      return -1;
    }
    else {
      cur = it->second;
    }
  }
  return cur;
}

void dfs( Trie *T, int cur, string s, int i ) {
  map< char, int >::iterator it;

  if ( i < s.length() ) {
    dfs( T, T[ cur ].children[ s[ i ] ], s, i + 1 );
  }
  else {
    if ( i != s.length() && T[ cur ].word ) {
      printf( "%s\n", s.c_str() );
    }

    for ( it = T[ cur ].children.begin(); it != T[ cur ].children.end(); ++it ) {
      dfs( T, it->second, s + it->first, i + 2 );
    }
  }
}

int main() {
  const int L = 25000 * 20;
  char s[ 21 ];
  int i, j, n, size;
  Trie *T = new Trie[ L ];

  size = 0;
  scanf( "%d", &n );
  while ( n-- ) {
    scanf( "%s", s );
    add( T, size, s );
  }

  scanf( "%d", &n );
  for ( i = 1; i <= n; ++i ) {
    scanf( "%s", s );
    printf( "Case #%d:\n", i );
    j = check( T, s );
    if ( j != -1 && !T[ j ].children.empty() ) {
      dfs( T, 0, s, 0 );
    }
    else {
      printf( "No match.\n" );
    }
  }

  return 0;
}
