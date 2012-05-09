/*
    PROG: milk3
    ID: mariosa1
    LANG: C++
*/
#include <cstdio>
#include <set>
#include <queue>
using namespace std;
struct Bucket {
    short A;
    short B;
    short C;
};
set< short > S;
void pour( short capA, short capB, short *A, short *B ) {
    while ( *A && *B < capB ) {
        *A -= 1;
        *B += 1;
    }
}
void bfs( short A, short B, short C ) {
    short tempA, tempB, tempC;
    Bucket front;
    bool state[ 21 ][ 21 ][ 21 ];
    queue< Bucket > Q;
    front.A = 0;
    front.B = 0;
    front.C = C;
    pour( C, A, &( front.C ), &( front.A ) );
    Q.push( front );
    front.A = 0;
    front.B = 0;
    front.C = C;
    pour( C, B, &( front.C ), &( front.B ) );
    Q.push( front );
    //S.insert( C );
    //state[ 0 ][ 0 ][ C ] = true;
    while ( !Q.empty() ) {
        front = Q.front();
        Q.pop();
        if ( state[ front.A ][ front.B ][ front.C ] ) {
            continue;
        }
        state[ front.A ][ front.B ][ front.C ] = true;
        if ( !front.A ) {
            S.insert( front.C );
            //continue;
        }
        tempA = front.A;
        tempB = front.B;
        tempC = front.C;
        if ( front.A ) {
            front.A = tempA;
            front.B = tempB;
            front.C = tempC;
            pour( A, B, &( front.A ), &( front.B ) );
            Q.push( front );
            front.A = tempA;
            front.B = tempB;
            front.C = tempC;
            pour( A, C, &( front.A ), &( front.C ) );
            Q.push( front );
        }
        if ( front.B ) {
            front.A = tempA;
            front.B = tempB;
            front.C = tempC;
            pour( B, A, &( front.B ), &( front.A ) );
            Q.push( front );
            front.A = tempA;
            front.B = tempB;
            front.C = tempC;
            pour( B, C, &( front.B ), &( front.C ) );
            Q.push( front );
        }
        if ( front.C ) {
            front.A = tempA;
            front.B = tempB;
            front.C = tempC;
            pour( C, A, &( front.C ), &( front.A ) );
            Q.push( front );
            front.A = tempA;
            front.B = tempB;
            front.C = tempC;
            pour( C, B, &( front.C ), &( front.B ) );
            Q.push( front );
        }
    }
}
int main() {
    bool space;
    short A, B, C;
    set< short >::iterator it;
    freopen( "milk3.in", "r", stdin );
    freopen( "milk3.out", "w", stdout );
    scanf( "%hd %hd %hd", &A, &B, &C );
    bfs( A, B, C );
    space = false;
    for ( it = S.begin(); it != S.end(); ++it ) {
        if ( space ) {
            putchar( ' ' );
        }
        else {
            space = true;
        }
        printf( "%hd", *it );
    }
    putchar( '\n' );
    fclose( stdin );
    fclose( stdout );
    return 0;
}
