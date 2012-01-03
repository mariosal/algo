/*
    ID: mariosa1
    LANG: C++
    TASK: namenum
*/
#include <cstdio>
#include <map>

using namespace std;

int main() {
    bool printed;
    char j, s[ 13 ];
    short i;
    long long n, q;
    FILE *dict;
    map< char, char > M;

    freopen( "namenum.in", "r", stdin );
    freopen( "namenum.out", "w", stdout );
    dict = fopen( "dict.txt", "r" );

    M[ 'A' ] = M[ 'B' ] = M[ 'C' ] = 2;
    M[ 'D' ] = M[ 'E' ] = M[ 'F' ] = 3;
    M[ 'G' ] = M[ 'H' ] = M[ 'I' ] = 4;
    M[ 'J' ] = M[ 'K' ] = M[ 'L' ] = 5;
    M[ 'M' ] = M[ 'N' ] = M[ 'O' ] = 6;
    M[ 'P' ] = M[ 'R' ] = M[ 'S' ] = 7;
    M[ 'T' ] = M[ 'U' ] = M[ 'V' ] = 8;
    M[ 'W' ] = M[ 'X' ] = M[ 'Y' ] = 9;

    scanf( "%lld", &n );

    printed = false;
    for ( i = 0; i < 4617; i += 1 ) {
        fscanf( dict, "%s", s );

        q = 0;
        for ( j = 0; s[ j ]; j += 1 ) {
            q *= 10;
            q += M[ s[ j ] ];
        }
        if ( n == q ) {
            puts( s );

            printed = true;
        }
    }
    if ( !printed ) {
        puts( "NONE" );
    }

    M.clear();
    fclose( stdin );
    fclose( stdout );
    fclose( dict );

    return 0;
}
