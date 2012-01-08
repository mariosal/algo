#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    char i;
    short A, D, min, j, array[ 11 ];
    
    //freopen( "in.txt", "r", stdin );

    while ( 1 ) {
        scanf( "%hd %hd", &A, &D );
        if ( !A ) {
            break;
        }

        min = 10000;
        while ( A-- ) {
            scanf( "%hd", &j );
            if ( min > j ) {
                min = j;
            }
        }

        for ( i = 0; i < D; ++i ) {
            scanf( "%hd", &array[ i ] );
        }
        nth_element( &array[ 0 ], &array[ 1 ], &array[ D ] );

        if ( min < array[ 1 ] ) {
            puts( "Y" );
        }
        else {
            puts( "N" );
        }
    }

    return 0;
}
