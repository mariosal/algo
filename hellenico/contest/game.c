#include <stdio.h>
#include <math.h>

int main() {
    char c, H, K, P, i;

    freopen( "game.in", "r", stdin );
    freopen( "game.out", "w", stdout );

    for ( i = 0; i < 10; ++i ) {
        scanf( "%c", &c );

        switch ( c ) {
            case 'H':
                H = i;
                break;
            case 'K':
                K = i;
                break;
            case 'P':
                P = i;
                break;
        }
    }

    if ( ( K < P && P < H ) ||
         ( H < P && P < K ) ) {
        puts( "-1" );
    }
    else {
        printf( "%d\n", abs( P - K ) + abs( H - K ) );
    }

    fclose( stdin );
    fclose( stdout );

    return 0;
}
