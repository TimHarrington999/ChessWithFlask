#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { WHITE = 0, BLACK = 1 } color;

typedef struct {
  uint64_t wp;
  uint64_t wr;
  uint64_t wn;
  uint64_t wb;
  uint64_t wq;
  uint64_t wk;

  uint64_t bp;
  uint64_t br;
  uint64_t bn;
  uint64_t bb;
  uint64_t bq;
  uint64_t bk;
} Board;

typedef struct {
  Board *board;
  color turn;

} Game;

// UCI Functions
void handle_uci();
void handle_isready();
void handle_position();
void handle_go();
void handle_quit();

// Main Functions
void board_load_startpos();
void board_move_piece(char *);
void board_load_fen(char *);

// Bitmap Functions
void set_bit(uint64_t *, int);
void clear_bit(uint64_t *, int);
void move_bit(uint64_t *, int, int);
