#include <cstdio>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    const short N = 8500;
    char ans, len, *buffer;
    short i;
    multiset< string > cube;

    for ( i = 1; i <= N; ++i ) {
        len = log10( ( long )i * i * i ) + 1;
        buffer = new char[ len + 1 ];

        sprintf( buffer, "%ld", ( long )i * i * i );
        sort( buffer, buffer + len );
        cube.insert( buffer );

        delete[] buffer;
    }

    for ( i = 1; i <= N; ++i ) {
        len = log10( ( long )i * i * i ) + 1;
        buffer = new char[ len + 1 ];

        sprintf( buffer, "%ld", ( long )i * i * i );
        sort( buffer, buffer + len );
        if ( cube.count( buffer ) == 5 ) {
            printf( "%ld\n", ( long )i * i * i );
            break;
        }

        delete[] buffer;
    }

    return 0;
}
