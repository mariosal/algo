#include <stdio.h>
#include <stdlib.h>

typedef struct Disjoint {
    struct Disjoint *parent;
    int rank;
} Disjoint;

Disjoint *find( Disjoint *set ) {
    if ( set->parent != NULL ) {
        set->parent = find( set->parent );
        return set->parent;
    }
    return set;
}
void unite( Disjoint *a, Disjoint *b ) {
    a = find( a );
    b = find( b );
    if ( a == b ) {
        return;
    }

    if ( a->rank > b->rank ) {
        b->parent = a;
    }
    else {
        a->parent = b;

        if ( a->rank == b->rank ) {
            b->rank += 1;
        }
    }
}

int main() {
    char cmd;
    int V, E, Q, i, p, r;
    Disjoint *caves;

    freopen( "caves.in", "r", stdin );
    freopen( "caves.out", "w", stdout );
    
    scanf( "%d %d", &V, &E );
    caves = ( Disjoint* )malloc( ( V + 200000 + 1 ) * sizeof( Disjoint ) );

    for ( i = 0; i < E; i += 1 ) {
        scanf( "%d %d", &p, &r );

        unite( &caves[ p ], &caves[ r ] );
    }

    scanf( "%d\n", &Q );
    for ( i = 0; i < Q; i += 1 ) {
        scanf( "%c %d %d\n", &cmd, &p, &r );

        if ( cmd == 'C' || cmd == 'P' ) {
            unite( &caves[ p ], &caves[ r ] );
        }
        else if ( cmd == 'Q' ) {
            if ( find( &caves[ p ] ) == find( &caves[ r ] ) ) {
                puts( "Y" );
            }
            else {
                puts( "N" );
            }
        }
    }

    return 0;
}
