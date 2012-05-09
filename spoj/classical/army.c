#include <stdio.h>

int main() {
    int T, q, i, j, maxI, maxJ;

    scanf( "%d", &T );
    while ( T-- ) {
        scanf( "%d %d", &i, &j );

        maxI = 0;
        while ( i-- ) {
            scanf( "%d", &q );
            if ( maxI < q ) {
                maxI = q;
            }
        }

        maxJ = 0;
        while ( j-- ) {
            scanf( "%d", &q );
            if ( maxJ < q ) {
                maxJ = q;
            }
        }

        if ( maxI >= maxJ ) {
            puts( "Godzilla" );
        }
        else {
            puts( "MechaGodzilla" );
        }
    }

    return 0;
}
