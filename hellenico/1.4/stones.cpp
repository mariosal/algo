#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct {
    short mass;
    unsigned short volume;
} Stone;

// Sort by the density
bool cmp( Stone a, Stone b ) {
    float dA, dB;
    dA = ( float )a.mass / a.volume;
    dB = ( float )b.mass / b.volume;
    return dA > dB;
}

int main() {
    int i, n, maxVolume;
    float ans;
    Stone *stones;

    freopen( "stones.in", "r", stdin );
    freopen( "stones.out", "w", stdout );

    scanf( "%d %d", &n, &maxVolume );
    stones = new Stone[ n ];

    for ( i = 0; i < n; ++i ) {
        scanf( "%hu %hd", &stones[ i ].volume, &stones[ i ].mass );
    }
    sort( stones, stones + n, cmp );

    ans = 0;
    for ( i = 0; i < n; ++i ) {
        if ( stones[ i ].volume <= maxVolume ) {
            ans += stones[ i ].mass;
            maxVolume -= stones[ i ].volume;
        }
        else {
            ans += ( float )stones[ i ].mass * maxVolume / stones[ i ].volume;
            break;
        }
    }
    printf( "%.3f\n", ans );

    return 0;
}
