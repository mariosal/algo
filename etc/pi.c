#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, inside;
    float x, y;
    const int N = 9876543; // accuracy

    srand( time( NULL ) );

    inside = 0;
    for ( i = 0; i < N; i += 1 ) {
        x = ( float )rand() / RAND_MAX;
        y = ( float )rand() / RAND_MAX;

        if ( x * x + y * y <= 1 ) {
            inside += 1;
        }
    }

    printf( "Pi: 3.141592\nEstimated: %f\n", ( float )4 * inside / N );

    return 0;
}
