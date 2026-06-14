#pragma once

#include "Board.h"

//typedef enum { WHITE = 0, BLACK = 1 } color;
enum class color;

class Game {

public:
  Game();
  ~Game();

  void load_startpos();
  void move_piece(char *);
  void load_fen(char *);

private:
  //typedef enum { WHITE = 0, BLACK = 1 } color;
  color m_color;
  Board *m_board;
};
