#include <stdio.h>

/*
 * center: 1
 * upright: n^2
 * upleft: upright -( n -1 )
 * downleft: upleft -( n -1 ) 
 * downright: downleft -( n -1 )
 */

#define N 1001

int main() {
    int i, sum;

    sum = 1;
    for ( i = 3; i <= N; i += 2 ) {
        sum += i * i;
        sum += i * i - 1 * ( i - 1 );
        sum += i * i - 2 * ( i - 1 );
        sum += i * i - 3 * ( i - 1 );
    }
    printf( "%d\n", sum );

    return 0;
}
