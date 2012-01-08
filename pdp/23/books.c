#include <stdio.h>
#include <stdlib.h>

char isValid( int books, int scribes, short *pages, int max ) {
    int i, needed, scribed;

    for ( i = scribed = 0, needed = 1; i < books; i += 1 ) {
        if ( pages[ i ] > max ) {
            return 0;
        }

        scribed += pages[ i ];
        if ( scribed > max ) {
            needed += 1;
            scribed = pages[ i ];
        }
    }

    return needed <= scribes;
}

int binarySearch( int books, int scribes, short *pages, int low, int high ) {
    int mid;

    while ( low <= high ) {
        mid = ( low + high ) / 2;

        if ( low == high ) {
            return mid;
        }
        if ( isValid( books, scribes, pages, mid ) ) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
}

int main() {
    short *pages;
    int books, scribes, i, sum;

    freopen( "books.in", "r", stdin );
    //freopen( "books.out", "w", stdout );

    scanf( "%d %d", &books, &scribes );
    pages = ( short* )malloc( books * sizeof( short ) );

    for ( i = sum = 0; i < books; ++i ) {
        scanf( "%hd", &pages[ i ] );

        sum += pages[ i ];
    }

    printf( "%hd\n", binarySearch( books, scribes, pages, 1, sum ) );

    return 0;
}
