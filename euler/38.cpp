#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int max( int a, int b ) {
    if ( a > b ) {
        return a;
    }
    return b;
}

int concat( int a, int b ) {
    char lenB;
    int ten;

    lenB = floor( log10( b ) ) + 1;
    ten = 1;
    while ( lenB-- ) {
        ten *= 10;
    }
    return a * ten + b;
}

int main() {
    char len;
    int ans, maxAns, i, j;
    string s;
    set< int > pandigitals;

    s = "123456789";
    do {
        pandigitals.insert( atoi( s.c_str() ) );
    } while ( next_permutation( s.begin(), s.end() ) );

    maxAns = 0;
    for ( i = 1; i <= 9999; ++i ) {
        ans = i;
        for ( j = 2; ; ++j ) {
            ans = concat( ans, i * j );
            len = floor( log10( ans ) ) + 1;

            if ( len == 9 ) {
                if ( pandigitals.find( ans ) != pandigitals.end() ) {
                    maxAns = max( maxAns, ans );
                }
            }
            else if ( len > 9 ) {
                break;
            }
        }
    }

    printf( "%d\n", maxAns );

    return 0;
}
