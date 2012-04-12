#include <stdio.h>  
#include <stdlib.h>  
  
void floyd( int **D, int V, int E ) {  
    int i, j, k;  
  
    for ( i = 0; i < V; ++i ) {  
        for ( j = 0; j < V; ++j ) {  
            for ( k = 0; k < V; ++k ) {  
                if ( D[ i ][ j ] > D[ i ][ k ] + D[ k ][ j ] ) {  
                    D[ i ][ j ] = D[ i ][ k ] + D[ k ][ j ];  
                }  
            }  
        }  
    }  
}  
  
int main() {  
    int i, j, p, r, w, A, B, C, V, E, L, **D;  
  
    freopen( "souvlakia.in", "r", stdin );  
    freopen( "souvlakia.out", "w", stdout );  
  
    scanf( "%d %d", &V, &E );  
  
    D = ( int** )malloc( ( V + 1 ) * sizeof( int* ) );  
    for ( i = 0; i <= V; ++i ) {  
        D[ i ] = ( int* )malloc( ( V + 1 ) * sizeof( int ) );  
        for ( j = 0; j <= V; ++j ) {  
            if ( i != j ) {  
                D[ i ][ j ] = 987654321;  
            }  
            else {  
                D[ i ][ j ] = 0;  
            }  
        }  
    }  
  
    for ( i = 0; i < E; ++i ) {  
        scanf( "%d %d %d", &p, &r, &w );  
        D[ p ][ r ] = w;  
        D[ r ][ p ] = w;  
    }  
  
    floyd( D, V, E );  
    scanf( "%d %d %d %d", &A, &B, &C, &L );  
    for ( i = 0; i < L; ++i ) {  
        scanf( "%d", &p );  
        for ( j = 1; j <= V; ++j ) {  
            if ( D[ A ][ p ] > D[ A ][ j ] && D[ B ][ p ] > D[ B ][ j ] && D[ C ][ p ] > D[ C ][ j ] ) {  
                printf( "NO\n" );  
                break;  
            }  
        }  
        if ( j > V ) {  
            printf( "YES\n" );  
        }  
    }  
  
    return 0;  
}  
