#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

void floyd( int **D, short V ) {
    short k, i, j;

    for ( k = 1; k <= V; k += 1 ) {
        for ( i = 1; i <= V; i += 1 ) {
            for ( j = 1; j <= V; j += 1 ) {
                if ( D[ i ][ j ] > D[ i ][ k ] + D[ k ][ j ] ) {
                    D[ i ][ j ] = D[ i ][ k ] + D[ k ][ j ];
                }
            }
        }
    }
}

int main() {
    char **broken, from[ 1000 ], to[ 1000 ], ar1[ 3 ], ar2[ 3 ];
    short N, C, R, i, j, q, w, prev;
    int **D, T;
    long long sum;
    map< string, short > M;

    //freopen( "in.txt", "r", stdin );

    T = 1;
    while ( 1 ) {
        scanf( "%hd %hd %hd", &N, &C, &R );
        if ( N == 0 && C == 0 && R == 0 ) {
            break;
        }

        broken = ( char** )malloc( ( C + 1 ) * sizeof( char* ) );
        for ( i = 0; i <= C; i += 1 ) {
            broken[ i ] = ( char* )malloc( 1000 );

            scanf( "%s", broken[ i ] );
        }

        D = ( int** )malloc( ( N + 1 ) * sizeof( int* ) );
        for ( i = 1; i <= N; i += 1 ) {
            D[ i ] = ( int* )malloc( ( N + 1 ) * sizeof( int ) );
            for ( j = 1; j <= N; j += 1 ) {
                D[ i ][ j ] = 987654321;
            }
        }

        q = 1;
        for ( i = 0; i < R; i += 1 ) {
            scanf( "%s %2s%hd%2s %s", from, ar1, &w, ar2, to );

            if ( M[ from ] == 0 ) {
                M[ from ] = q;
                q += 1;
            }
            if ( M[ to ] == 0 ) {
                M[ to ] = q;
                q += 1;
            }

            if ( !strcmp( ar1, "<-" ) && D[ M[ to ] ][ M[ from ] ] > w ) {
                D[ M[ to ] ][ M[ from ] ] = w;
            }
            if ( !strcmp( ar2, "->" ) && D[ M[ from ] ][ M[ to ] ] > w ) {
                D[ M[ from ] ][ M[ to ] ] = w;
            }
        }

        floyd( D, N );

        sum = 0;
        for ( i = 1; i <= C; i += 1 ) {
            sum += D[ M[ broken[ 0 ] ] ][ M[ broken[ i ] ] ];
            sum += D[ M[ broken[ i ] ] ][ M[ broken[ 0 ] ] ];
        }

        printf( "%d. %lld\n", T, sum );

        T += 1;
        M.clear();
    }

    return 0;
}
