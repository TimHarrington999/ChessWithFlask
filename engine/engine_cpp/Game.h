#include "Board.h"

typedef enum { WHITE = 0, BLACK = 1 } color;

class Game {
private:
  color m_color;
  Board board;

public:
  void load_startpos();
  void move_piece(char *);
  void board_load_fen(char *);
};
