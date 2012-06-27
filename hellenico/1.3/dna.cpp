#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    char *s;
    short n, k, i, j, q, minSwaps, swaps, iters, minDna, dna[ 4 ];

    freopen( "dna.in", "r", stdin );
    freopen( "dna.out", "w", stdout );

    scanf( "%hd %hd", &n, &k );
    s = new char[ n ];
    scanf( "%s", s );

    minSwaps = SHRT_MAX;
    for ( i = k; i > 0; --i ) {
        swaps = 0;
        for ( j = 0; j < i; ++j ) {
            for ( q = 0; q < 4; ++q ) {
                dna[ q ] = 0;
            }
            iters = 0;

            for ( q = j; q < n; q += i ) {
                switch ( s[ q ] ) {
                    case 'A':
                        ++dna[ 0 ];
                        break;
                    case 'C':
                        ++dna[ 1 ];
                        break;
                    case 'G':
                        ++dna[ 2 ];
                        break;
                    case 'T':
                        ++dna[ 3 ];
                        break;
                }
                ++iters;
            }

            minDna = SHRT_MAX;
            for ( q = 0; q < 4; ++q ) {
                dna[ q ] = iters - dna[ q ];
                minDna = min( minDna, dna[ q ] );
            }
            swaps += minDna;
        }
        minSwaps = min( minSwaps, swaps );
    }
    printf( "%hd\n", minSwaps );

    return 0;
}
