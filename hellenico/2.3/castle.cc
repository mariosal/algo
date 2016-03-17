/*
  ID: mariosa1
  TASK: castle
  LANG: C++11
*/
#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>
#include <vector>

struct Point {
  bool operator<(const Point& p) const {
    if (x == p.x) {
      return y < p.y;
    }
    return x < p.x;
  }

  int x;
  int y;
};

static int current_room;
static int** room;

static int Fill(std::set<Point>& marked, bool*** walls, int rows, int cols,
                const Point& p) {
  if (p.x < 0 || rows <= p.x ||
      p.y < 0 || cols <= p.y) {
    return 0;
  }
  if (!marked.insert(p).second) {
    return 0;
  }

  room[p.x][p.y] = current_room;
  int ret = 1;
  int dr[4] = {-1, 0, 1, 0};
  int dc[4] = {0, 1, 0, -1};
  for (int i = 0; i < 4; ++i) {
    if (!walls[p.x][p.y][0]) {
      ret += Fill(marked, walls, rows, cols, {p.x + 1, p.y});
    }
    if (!walls[p.x][p.y][1]) {
      ret += Fill(marked, walls, rows, cols, {p.x, p.y + 1});
    }
    if (!walls[p.x][p.y][2]) {
      ret += Fill(marked, walls, rows, cols, {p.x - 1, p.y});
    }
    if (!walls[p.x][p.y][3]) {
      ret += Fill(marked, walls, rows, cols, {p.x, p.y - 1});
    }
  }
  return ret;
}

int main() {
  freopen("castle.in", "r", stdin);
  freopen("castle.out", "w", stdout);

  int cols, rows;
  scanf("%d%d", &rows, &cols);

  bool*** walls = new bool**[rows];
  for (int i = 0; i < rows; ++i) {
    walls[i] = new bool*[cols];
    for (int j = 0; j < cols; ++j) {
      int mask;
      scanf("%d", &mask);
      walls[i][j] = new bool[4]();
      if (mask >= 8) {
        walls[i][j][0] = true;
        mask -= 8;
      }
      if (mask >= 4) {
        walls[i][j][1] = true;
        mask -= 4;
      }
      if (mask >= 2) {
        walls[i][j][2] = true;
        mask -= 2;
      }
      if (mask >= 1) {
        walls[i][j][3] = true;
        mask -= 1;
      }
    }
  }

  room = new int*[rows];
  for (int i = 0; i < rows; ++i) {
    room[i] = new int[cols];
  }

  std::vector<int> areas;
  std::set<Point> marked;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (marked.find({i, j}) == marked.end()) {
        current_room = areas.size();
        areas.push_back(Fill(marked, walls, rows, cols, {i, j}));
      }
    }
  }
  int max_size = *std::max_element(areas.begin(), areas.end());
  printf("%d\n%d\n", areas.size(), max_size);

  std::pair<Point, char> max_point;
  for (int j = cols - 1; j >= 0; --j) {
    for (int i = 0; i < rows; ++i) {
      if (j < cols - 1 && walls[i][j][1] && room[i][j] != room[i][j + 1]) {
        int ans = areas[room[i][j]] + areas[room[i][j + 1]];
        if (max_size <= ans) {
          max_size = ans;
          max_point.first = {i, j};
          max_point.second = 'E';
        }
      }
      if (i > 0 && walls[i][j][2] && room[i][j] != room[i - 1][j]) {
        int ans = areas[room[i][j]] + areas[room[i - 1][j]];
        if (max_size <= ans) {
          max_size = ans;
          max_point.first = {i, j};
          max_point.second = 'N';
        }
      }
    }
  }
  printf("%d\n%d %d %c\n", max_size, max_point.first.x + 1,
         max_point.first.y + 1, max_point.second);

  return 0;
}
