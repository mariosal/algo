#include <cstdio>
#include <cmath>

int main() {
    int i, j, ans, sols, maxSols, p;
    double q;

    maxSols = 0;
    for ( p = 3; p <= 1000; ++p ) {
        sols = 0;
        for ( i = 1; i < p; ++i ) {
            for ( j = 1; j <= i; ++j ) {
                q = sqrt( i * i + j * j );
                if ( i + j + q == p ) {
                    ++sols;
                }
            }
        }
        if ( maxSols < sols ) {
            maxSols = sols;
            ans = p;
        }
    }
    printf( "%d\n", ans );

    return 0;
}
