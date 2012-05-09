#include <cstdio>
#include <stack>
#include <list>

using namespace std;

short dfs( list< short > L[ 5001 ], short start ) {
    short top, max, i;
    stack< short > S;
    list< short >::iterator it;

    max = i = 0;
    S.push( start );
    while ( !S.empty() ) {
        top = S.top();
        S.pop();

        ++i;
        for ( it = L[ top ].begin(); it != L[ top ].end(); ++it ) {
            if ( *it != start ) {
                S.push( *it );
            }
            else {
                if ( max < i ) {
                    max = i;
                }
            }
        }
    }

    return max;
}

int main() {
    short N, i, p, r, j, max;
    list< short > L[ 5001 ];

    freopen( "travel.in", "r", stdin );
    freopen( "travel.out", "w", stdout );

    scanf( "%hd", &N );
    for ( i = 1; i <= N; ++i ) {
        scanf( "%hd %hd", &p, &r );

        L[ p ].push_back( r );
    }

    max = 0;
    for ( i = 1; i <= N; ++i ) {
        j = dfs( L, i );

        if ( max < j ) {
            max = j;
        }
    }
    printf( "%hd\n", max );

    fclose( stdin );
    fclose( stdout );

    return 0;
}
