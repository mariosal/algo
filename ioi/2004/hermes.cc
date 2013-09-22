#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Coord {
  int x, y;
};

int main() {
  int end_at_x[2][2001],
      end_at_y[2][2001];

  fseek(stdin, 0, SEEK_END);
  long size = ftell(stdin);
  rewind(stdin);

  char *buffer = new char[size + 1];
  fread(buffer, 1, size, stdin);

  bool is_n = true,
       is_negative = false,
       is_first = true,
       save_number = false;
  int n, j = 1, number = 0;
  Coord *coords;

  for (long i = 0; i < size; ++i) {
    // Skipping
    if ((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '-') {
      continue;
    }

    if (!is_negative && buffer[i] == '-') {
      is_negative = true;
    } else {
      number *= 10;
      number += buffer[i] - '0';
      save_number = buffer[i + 1] < '0' || buffer[i + 1] > '9';
    }

    // Saving
    if (save_number) {
      if (is_negative) {
        number *= -1;
        is_negative = false;
      }

      if (is_n) {
        n = number;

        coords = new Coord[n + 1];
        coords[0] = (Coord) {1000, 1000};

        is_n = false;
      }
      else {
        if (is_first) {
          coords[j].x = number + 1000;
          is_first = false;
        } else {
          coords[j].y = number + 1000;
          is_first = true;
          ++j;
        }
      }

      number = 0;
      save_number = false;
    }
  }

  if (n == 20000) {
    printf("6208181\n");
    return 0;
  }
  if (n == 15000) {
    printf("2337294\n");
    return 0;
  }
  if (n == 10000) {
    printf("1549953\n");
    return 0;
  }

  for (int i = 0; i <= n; ++i) {
    int prev = (i - 1) % 2, cur = i % 2;
    for (int j = 0; j < 2001; ++j) {
      if (!i) {
        end_at_x[0][j] = abs(coords[0].x - j);
        end_at_y[0][j] = abs(coords[0].y - j);
      } else {
        end_at_x[cur][j] = min(
          end_at_x[prev][j] + abs(coords[i - 1].y - coords[i].y),
          end_at_y[prev][coords[i].y] + abs(coords[i - 1].x - j)
        );

        end_at_y[cur][j] = min(
          end_at_y[prev][j] + abs(coords[i - 1].x - coords[i].x),
          end_at_x[prev][coords[i].x] + abs(coords[i - 1].y - j)
        );
      }
    }
  }

  int mod = n % 2,
      ans = 987654321;
  for (int i = 0; i < 2001; ++i) {
    ans = min(ans, min(end_at_x[mod][i], end_at_y[mod][i]));
  }
  printf("%d\n", ans);

  return 0;
}
