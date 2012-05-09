/*
    PROG: crypt1
    ID: mariosa1
    LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
char check( set< char > S, int N ) {
    char i, numbers[ 10 ];
    sprintf( numbers, "%d", N );
    for ( i = 0; numbers[ i ] != '\0'; ++i ) {
        if ( S.find( numbers[ i ] - '0' ) == S.end() ) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int i, j, q, N;
    set< char > S;
    freopen( "crypt1.in", "r", stdin );
    freopen( "crypt1.out", "w", stdout );
    scanf( "%d", &N );
    for ( i = 0; i < N; ++i ) {
        scanf( "%d", &j );
        S.insert( j );
    }
    q = 0;
    for ( i = 100; i <= 999; ++i ) {
        if ( check( S, i ) ) {
            for ( j = 10; j <= 99; ++j ) {
                if ( check( S, j ) &&
                     i * j / 10000 == 0 &&
                     i * ( ( int )j / 10 ) / 1000 == 0 &&
                     i * ( ( int )j % 10 ) / 1000 == 0 ) {
                    if ( check( S, i * ( ( int )j / 10 ) ) &&
                         check( S, i * ( ( int )j % 10 ) ) &&
                         check( S, i * j ) ) {
                        ++q;
                    }
                }
            }
        }
    }
    printf( "%d\n", q );
    return 0;
}
