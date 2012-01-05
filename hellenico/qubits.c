#include <stdio.h>

void qubits( short N, char from, char to, char not ) {
    if ( N ) {
        qubits( N - 1, from, not, to );
        printf( "%c %c\n", from, to );
        qubits( N - 1, not, to, from );
    }
}

int main() {
    short N;

    freopen( "qubits.in", "r", stdin );
    freopen( "qubits.out", "w", stdout );

    scanf( "%hd", &N );
    qubits( N, 'A', 'C', 'B' );

    fclose( stdin ); 
    fclose( stdout ); 

    return 0;
}
