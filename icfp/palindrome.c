#include <stdio.h>
#include <stdlib.h>

int main() {
    char *string, *pal;
    int size, i, j, max, mini, maxj;

    fseek( stdin, 0, SEEK_END );
    size = ftell( stdin );
    rewind( stdin );

    string = ( char* )malloc( size );
    pal = ( char* )malloc( size );
    fread( string, 1, size, stdin );

    max = 0;
    for ( i = 0; i < size; i += 1 ) {
        j = 1;
        while ( i - j >= 0 && i + j < size ) {
            if ( string[ i - j ] != string[ i + j ] ) {
                break;
            }
            j += 1;
        }
        if ( max < 2 * j - 1 ) {
            max = 2 * j - 1;
            mini = i - j + 1;
            maxj = i + j - 1;
        }

        j = 0;
        while ( i - j >= 0 && i + j + 1 < size ) {
            if ( string[ i - j ] != string[ i + j + 1 ] ) {
                break;
            }
            j += 1;
        }
        if ( max < 2 * j ) {
            max = 2 * j;
            mini = i - j + 1;
            maxj = i + j;
        }
    }

    printf( "%d\n", max );
    for ( i = mini; i <= maxj; i += 1 ) {
        printf( "%c", string[ i ] );
    }
    putchar( '\n' );

    return 0;
}
