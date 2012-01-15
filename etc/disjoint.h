#include <stdio.h>

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
