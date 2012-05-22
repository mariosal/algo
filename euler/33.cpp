#include <cstdio>

bool isReducable( char a, char b ) {
    if ( a % 10 == b / 10 ) {
        if ( ( float )a / b == ( float )( a / 10 ) / ( b % 10 ) ) {
            return true;
        }
    }
    return false;
}

int main() {
    char i, j;

    for ( i = 10; i <= 99; ++i ) {
        for ( j = i + 1; j <= 99; ++j ) {
            if ( isReducable( i, j ) ) {
                printf( "%d / %d\n", i, j );
            }
        }
    }

    return 0;
}
