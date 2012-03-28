#include <stdio.h>
#include <stdlib.h>

#define N 1000000

int main() {
    char *num;
    int i, j, q, sum, maxSum, maxLen, *prime;

    num = ( char* )calloc( N - 2, 1 );
    prime = ( int* )malloc( ( N - 2 )  * sizeof( int ) );

    for ( i = 2; i * i < N; ++i ) {
        if ( !num[ i - 2 ] ) {
            for ( j = i * i; j < N; j += i ) {
                num[ j - 2 ] = 1;
            }
        }
    }

    q = 0;
    for ( i = 2; i < N; ++i ) {
        if ( !num[ i - 2 ] ) {
            prime[ q ] = i;
            ++q;
        }
    }

    maxLen = 0;
    for ( i = 0; i < q; ++i ) {
        sum = 0;
        for ( j = i; j < q; ++j ) {
            sum += prime[ j ];
            if ( sum >= N ) {
                break;
            }
            if ( !num[ sum - 2 ] && maxLen < j - i + 1 ) {
                maxLen = j - i + 1;
                maxSum = sum;
            }
        }
    }
    printf( "%d\n", maxSum );

    return 0;
}
