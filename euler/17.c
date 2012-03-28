#include <stdio.h>
#include <stdio.h>
#include <string.h>

int one( char **a, int i ) {
    return strlen( a[ i ] );
}
int lt100( char **a, int i ) {
    return strlen( a[ i / 10 * 10 ] ) + one( a, i % 10 );
}
int lt1000( char **a, int i ) {
    int ans = strlen( a[ i / 100 * 100 ] );
    if ( i % 100 ) {
        ans += 3;
    }
    if ( i % 100 <= 20 ) {
        ans += one( a, i % 100 );
    }
    else {
        ans += lt100( a, i % 100 );
    }
    return ans;
}

int main() {
    char *a[ 10000 ];
    int i, ans;

    a[ 0 ] = "";
    a[ 1 ] = "one";
    a[ 2 ] = "two";
    a[ 3 ] = "three";
    a[ 4 ] = "four";
    a[ 5 ] = "five";
    a[ 6 ] = "six";
    a[ 7 ] = "seven";
    a[ 8 ] = "eight";
    a[ 9 ] = "nine";
    a[ 10 ] = "ten";
    a[ 11 ] = "eleven";
    a[ 12 ] = "twelve";
    a[ 13 ] = "thirteen";
    a[ 14 ] = "fourteen";
    a[ 15 ] = "fifteen";
    a[ 16 ] = "sixteen";
    a[ 17 ] = "seventeen";
    a[ 18 ] = "eighteen";
    a[ 19 ] = "nineteen";
    a[ 20 ] = "twenty";
    a[ 30 ] = "thirty";
    a[ 40 ] = "forty";
    a[ 50 ] = "fifty";
    a[ 60 ] = "sixty";
    a[ 70 ] = "seventy";
    a[ 80 ] = "eighty";
    a[ 90 ] = "ninety";
    a[ 100 ] = "onehundred";
    a[ 200 ] = "twohundred";
    a[ 300 ] = "threehundred";
    a[ 400 ] = "fourhundred";
    a[ 500 ] = "fivehundred";
    a[ 600 ] = "sixhundred";
    a[ 700 ] = "sevenhundred";
    a[ 800 ] = "eighthundred";
    a[ 900 ] = "ninehundred";
    a[ 1000 ] = "onethousand";

    ans = 0;
    for ( i = 1; i <= 1000; ++i ) {
        if ( i <= 20 || i == 1000 ) {
            ans += one( a, i );
        }
        else if ( i < 100 ) {
            ans += lt100( a, i );
        }
        else if ( i < 1000 ) {
            ans += lt1000( a, i );
        }
    }
    printf( "%d\n", ans );

    return 0;
}
