#include <cstdio>
#include <cmath>
#include <set>

using namespace std;

int gcd( int a, int b ) {
    if ( !b ) {
        return a;
    }
    return gcd( b, a % b );
}

int main() {
    const int N = 1500000;
    char *mark;
    int ans, sum, i, j, k, a, b, c;

    mark = new char[ N + 1 ];
    for ( i = 0; i <= N; ++i ) {
        mark[ i ] = 0;
    }

    for ( i = 1; i * i < N; i += 2 ) {
        for ( j = 1; j * j < N; ++j ) {
            if ( gcd( i, j ) == 1 && ( i - j ) % 2 ) {
                a = abs( i * i - j * j );
                b = 2 * i * j;
                c = i * i + j * j;
                sum = a + b + c;
                for ( k = 1; k * sum <= N; ++k ) {
                    ++mark[ k * sum ];
                }
            }
        }
    }

    ans = 0;
    for ( i = 0; i <= N; ++i ) {
        if ( mark[ i ] == 1 ) {
            ++ans;
        }
    }
    printf( "%d\n", ans );

    return 0;
}
