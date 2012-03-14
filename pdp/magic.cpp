#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    char i;
    int sum, count, a[ 9 ];

    for ( i = 0; i < 9; i += 1 ) {
        scanf( "%d", &a[ i ] );
    }

    count = 0;
    sort( a, a + 9 );
    do {
        sum = a[ 0 ] + a[ 1 ] + a[ 2 ];
        if ( a[ 3 ] + a[ 4 ] + a[ 5 ] == sum &&
             a[ 6 ] + a[ 7 ] + a[ 8 ] == sum &&
             a[ 0 ] + a[ 3 ] + a[ 6 ] == sum &&
             a[ 1 ] + a[ 4 ] + a[ 7 ] == sum &&
             a[ 2 ] + a[ 5 ] + a[ 8 ] == sum ) {
            count += 1;
        }
    } while ( next_permutation( a, a + 9 ) );

    printf( "%d\n", count );

    return 0;
}
