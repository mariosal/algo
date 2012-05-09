#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>

using namespace std;

char checkPal( string s, int len ) {
    int i, mid;

    for ( i = 0; i < len / 2; ++i ) {
        if ( s[ i ] != s[ len - i - 1 ] ) {
            return 0;
        }
    }

    return 1;
}

int bf( char *s, int len ) {
    int i;
    string front;
    queue< string > q;

    front = s;
    q.push( front );
    while ( !q.empty() ) {
        front = q.front();
        q.pop();

        if ( checkPal( front, ( int )front.length() ) ) {
            break;
        }

        front += s[ 0 ];
        q.push( front );
        for ( i = 1; i < len; ++i ) {
            front[ front.length() - 1 ] = s[ i ];
            q.push( front );
        }
    }

    return ( int )front.length();
}

int main() {
    char *s;
    int n;

    freopen( "minpali.in", "r", stdin );
    freopen( "minpali.out", "w", stdout );

    scanf( "%d", &n );
    s = ( char* )malloc( n + 1 );
    scanf( "%s", s );

    printf( "%d\n", bf( s, n ) );

    return 0;
}
