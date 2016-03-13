/*
  ID: mariosa1
  TASK: transform
  LANG: C++11
*/
#include <cstdio>
#include <cstring>

#ifdef _LP64
#define __PRIS_PREFIX "z"
#else
#define __PRIS_PREFIX
#endif

#define PRIuS __PRIS_PREFIX "u"

class Board {
 public:
  Board(size_t size) : size_(size), tiles_(new char*[size_]) {
    for (size_t i = 0; i < size_; ++i) {
      tiles_[i] = new char[size_ + 1];
    }
  }
  Board(const Board& board) : size_(board.size_), tiles_(new char*[size_]) {
    for (size_t i = 0; i < size_; ++i) {
      tiles_[i] = new char[size_ + 1];
      strcpy(tiles_[i], board.tiles_[i]);
    }
  }
  ~Board() {
    for (size_t i = 0; i < size_; ++i) {
      delete tiles_[i];
    }
    delete[] tiles_;
  }
  bool operator==(const Board& board) const {
    if (size_ == board.size_) {
      for (size_t i = 0; i < size_; ++i) {
        if (strcmp(tiles_[i], board.tiles_[i]) != 0) {
          return false;
        }
      }
      return true;
    }
    return false;
  }

  void Read() {
    for (size_t i = 0; i < size_; ++i) {
      scanf("%s", tiles_[i]);
    }
  }
  Board Reflect() const {
    Board ret(size_);
    for (size_t i = 0; i < size_; ++i) {
      for (size_t j = 0; j < size_; ++j) {
        ret.tiles_[i][size_ - j - 1] = tiles_[i][j];
      }
    }
    return ret;
  }
  Board Rotate() const {
    Board ret(size_);
    for (size_t i = 0; i < size_; ++i) {
      for (size_t j = 0; j < size_; ++j) {
        ret.tiles_[j][size_ - i - 1] = tiles_[i][j];
      }
    }
    return ret;
  }

 private:
  size_t size_;
  char** tiles_;
};

int main() {
  freopen("transform.in", "r", stdin);
  freopen("transform.out", "w", stdout);

  size_t size;
  scanf("%" PRIuS, &size);

  Board a(size);
  a.Read();

  Board b(size);
  b.Read();

  int id;
  if (a.Rotate() == b) {
    id = 1;
  } else if (a.Rotate().Rotate() == b) {
    id = 2;
  } else if (a.Rotate().Rotate().Rotate() == b) {
    id = 3;
  } else if (a.Reflect() == b) {
    id = 4;
  } else if (a.Rotate().Reflect() == b || a.Rotate().Rotate().Reflect() == b ||
             a.Rotate().Rotate().Rotate().Reflect() == b) {
    id = 5;
  } else if (a == b) {
    id = 6;
  } else {
    id = 7;
  }

  printf("%d\n", id);
  return 0;
}
