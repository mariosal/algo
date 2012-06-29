#include <cstdio>
#include <cmath>

int main() {
    int n, m, a;

    scanf( "%d %d %d", &n, &m, &a );
    printf( "%I64d\n", ( long long )ceil( ( double )n / a ) * ( long long )ceil( ( double )m / a ) );

    return 0;
}
