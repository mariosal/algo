#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct {
    long long amount;
    short type;
} item;

typedef struct {
    unsigned long long best;
    short i;
    short j;
    vector< item > box;
    vector< item > toy;
} state;

unsigned long long bf( state top ) {
    unsigned long long best;
    state next;
    stack< state > s;

    best = 0;
    s.push( top );
    while ( !s.empty() ) {
        top = s.top();
        s.pop();

        if ( best < top.best ) {
            best = top.best;
        }
        if ( top.i >= top.box.size() || top.j >= top.toy.size() ) {
            continue;
        }

        next = top;
        if ( next.box[ next.i ].type == next.toy[ next.j ].type ) {
            if ( next.box[ next.i ].amount > next.toy[ next.j ].amount ) {
                next.best += ( unsigned long long )next.toy[ next.j ].amount;
                next.box[ next.i ].amount -= next.toy[ next.j ].amount;
                ++next.j;
            }
            else {
                next.best += ( unsigned long long )next.box[ next.i ].amount;
                next.toy[ next.j ].amount -= next.box[ next.i ].amount;
                ++next.i;
            }
            s.push( next );
            continue;
        }

        next = top;
        ++next.i;
        s.push( next );

        next = top;
        ++next.j;
        s.push( next );
    }

    return best;
}

int main() {
    short t, i, j, cntBox, cntToy;
    state top;

    scanf( "%hd", &t );
    for ( i = 1; i <= t; ++i ) {
        scanf( "%hd %hd", &cntBox, &cntToy );
        top.box.resize( cntBox );
        top.toy.resize( cntToy );

        for ( j = 0; j < cntBox; ++j ) {
            scanf( "%lld %hd", &top.box[ j ].amount, &top.box[ j ].type );
        }
        for ( j = 0; j < cntToy; ++j ) {
            scanf( "%lld %hd", &top.toy[ j ].amount, &top.toy[ j ].type );
        }

        top.best = 0;
        top.i = 0;
        top.j = 0;
        printf( "Case #%hd: %llu\n", i, bf( top ) );
    }

    return 0;
}
