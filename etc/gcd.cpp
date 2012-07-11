#include <cstdio>
#include <utility>

using namespace std;

pair< int, int > extended_gcd( int a, int b ) {
  int x, y, lastX, lastY, q, r, t;

  x = 0;
  y = 1;
  lastX = 1;
  lastY = 0;
  while ( b ) {
    q = a / b;

    t = b;
    b = a % b;
    a = t;

    t = x;
    x = lastX - q * x;
    lastX = t;

    t = y;
    y = lastY - q * y;
    lastY = t;
  }

  return make_pair( lastX, lastY );
}

int main() {
  pair< int, int > sol;

  sol = extended_gcd( 120, 23 );
  printf( "%d %d\n", sol.first, sol.second );

  return 0;
}
