#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main() {
    char s[ 32 ];
    int t, n;
    map< string, int > M;
    map< string, int >::iterator it;

    //freopen( "in.txt", "r", stdin );

    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d", &n );
        getchar();
        while ( n-- ) {
            gets( s );
            ++M[ s ];
        }

        for ( it = M.begin(); it != M.end(); ++it ) {
            printf( "%s %d\n", it->first.c_str(), it->second );
        }
        if ( t > 0 ) {
            putchar( '\n' );
        }

        M.clear();
    }

    return 0;
}
