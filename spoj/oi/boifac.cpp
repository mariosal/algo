#include <cstdio>
#include <cmath>

int facLen( int n ) {
    static int curMemo;
    static float *memo = new float[ 36352 ];

    if ( !curMemo ) {
        memo[ 0 ] = 1;
    }
    for ( ; curMemo < n; ++curMemo ) {
        memo[ curMemo + 1 ] = memo[ curMemo ] + log10( curMemo + 1 );
    }
    return memo[ n ];
}

int main() {
    int i, maxLen, cntAns, *ans;
    
    ans = new int[ 36352 ];

    scanf( "%d", &maxLen );
    cntAns = 0;
    for ( i = 1; facLen( i ) <= maxLen; ++i ) {
        if ( facLen( i ) == maxLen ) {
            ans[ cntAns ] = i;
            ++cntAns;
        }
    }

    if ( cntAns ) {
        printf( "%d\n", cntAns );
        for ( i = 0; i < cntAns; ++i ) {
            printf( "%d\n", ans[ i ] );
        }
    }
    else {
        printf( "NO\n" );
    }

    return 0;
}
