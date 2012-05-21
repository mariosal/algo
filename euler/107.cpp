#include <cstdio>
#include <list>
#include <set>
#include <queue>

using namespace std;

struct Edge {
    char v;
    int w;
};
bool operator <( Edge a, Edge b ) {
    if ( a.w == b.w ) {
        return a.v < b.v;
    }
    return a.w < b.w;
}
Edge makeEdge( char v, int w ) {
    Edge ret;

    ret.v = v;
    ret.w = w;

    return ret;
}

int prim( list< Edge > *E ) {
    int sum;
    Edge front;
    set< int > mark;
    set< Edge > s;
    list< Edge >::iterator it;

    sum = 0;
    s.insert( makeEdge( 0, 0 ) );
    while ( !s.empty() ) {
        front = *s.begin();
        s.erase( s.begin() );

        if ( mark.insert( front.v ).second ) {
            sum += front.w;
            for ( it = E[ front.v ].begin(); it != E[ front.v ].end(); ++it ) {
                s.insert( *it );
            }
        }
    }
    return sum;
}

int main() {
    const char N = 40;
    char i, j;
    int w;
    int originalSum, sum;
    list< Edge > *E;

    originalSum = 0;
    E = new list< Edge >[ N ];
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            scanf( "%d", &w );
            if ( w ) {
                originalSum += w;
                E[ i ].push_back( makeEdge( j, w ) );
            }
        }
    }
    originalSum /= 2;

    sum = prim( E );
    printf( "%d - %d = %d\n", originalSum, sum, originalSum - sum );

    return 0;
}
