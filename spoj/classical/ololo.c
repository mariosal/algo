#include <stdio.h>

int main() {
    int N, Pi, once;
    
    scanf( "%d", &N );

    once = 0;
    while ( N-- ) {
        scanf( "%d", &Pi );

        once = once ^ Pi;
    }

    printf( "%d\n", once );

    return 0;
}
