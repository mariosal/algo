/*
  ID: mariosa1
  LANG: C
  TASK: gift1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Person {
  char name[ 15 ];
  int total;
} Person;

Person* map( char *string, Person *people ) {
  char i;
  for ( i = 0; ; i += 1 ) {
    if ( !strcmp( people[ i ].name, string ) ) {
      return &people[ i ];
    }
  }
}

int main() {
  char i, j, name[ 15 ];
  short NP, NG, money;
  Person *people, *other;

  freopen( "gift1.in", "r", stdin );
  freopen( "gift1.out", "w", stdout );

  scanf( "%hd", &NP );

  people = ( Person* )malloc( NP * sizeof( Person ) );
  for ( i = 0; i < NP; i += 1 ) {
    scanf( "%s", name );
    strcpy( people[ i ].name, name );
    people[ i ].total = 0;
  }

  for ( i = 0; i < NP; i += 1 ) {
    scanf( "%s\n%hd %hd", name, &money, &NG );

    if ( NG == 0 || money == 0 ) {
      continue;
    }

    other = map( name, people );
    other->total -= floor( money / NG ) * NG;

    for ( j = 0; j < NG; j += 1 ) {
      scanf( "%s", name );
      other = map( name, people );

      other->total += money / NG;
    }
  }

  for ( i = 0; i < NP; i += 1 ) {
    printf( "%s %d\n", people[ i ].name, people[ i ].total );
  }

  return 0;
}
