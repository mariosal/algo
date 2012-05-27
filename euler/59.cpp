#include <cstdio>
#include <cstring>
#include <cctype>

int main() {
    bool valid;
    char i, j, k, key[ 4 ], *text, *copyText;
    short l, len, dummy;
    int sum;

    scanf( "%hd\n", &len );

    text = new char[ len + 1 ];
    text[ len ] = '\0';
    copyText = new char[ len + 1 ];

    for ( l = 0; l < len; ++l ) {
        scanf( "%hd", &dummy );
        text[ l ] = dummy;
    }

    key[ 3 ] = '\0';
    for ( i = 97; i <= 122; ++i ) {
        key[ 0 ] = i;
        for ( j = 97; j <= 122; ++j ) {
            key[ 1 ] = j;
            for ( k = 97; k <= 122; ++k ) {
                key[ 2 ] = k;

                sum = 0;
                valid = true;
                copyText[ len ] = '\0';
                for ( l = 0; l < len; ++l ) {
                    copyText[ l ] = text[ l ] ^ key[ l % 3 ];
                    sum += copyText[ l ];

                    if ( !isalnum( copyText[ l ] ) &&
                         !isspace( copyText[ l ] ) &&
                         copyText[ l ] != '('      &&
                         copyText[ l ] != ')'      &&
                         copyText[ l ] != ','      &&
                         copyText[ l ] != '.'      &&
                         copyText[ l ] != '!'      &&
                         copyText[ l ] != ';'      &&
                         copyText[ l ] != '\'' ) {
                        valid = false;
                        break;
                    }
                }
                if ( valid ) {
                    printf( "%d\n%s\n", sum, copyText );
                }
            }
        }
    }

    return 0;
}
