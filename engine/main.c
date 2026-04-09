// Timothy's Custom Chess Engine
//
// This engine uses UCI (Universal Chess Interface) to communicate with the
// front-end.
//

//
// ## Overview ##
// This connects with Flask through the python class UCIEngine via pipe.
// Communication is first established through the handle_uci() function like a
// handshake.
// Flask will tell us the board position and then how far to search
// for a move.
//

#include "main.h"
#include <stdlib.h>

#define MAX_LINE 1024

bool running = true;

Game *game; // global for simplicity

//
// #################
// # UCI Functions #
// #################
//

void handle_uci() {
  printf("id name TimothyChessEngine\n");
  printf("id author TimothyHarrington\n");
  printf("uciok\n");
  fflush(stdout);
}

void handle_isready() {
  printf("readyok\n");
  fflush(stdout);
}

// There are three possibilities when handling position
// 1. (Just the start position) - 'startpos'
// 2. (start position and a move sequence) - 'startpos moves e2e4 e7e5'
// 3. (FEN string) - 'fen <FEN>'
void handle_position() {
  return;

  char word[9];

  while (fgets(word, sizeof(word), stdin)) {
    word[strcspn(word, "\n")] = 0;

    if (strcmp(word, "startpos") == 0) {
      board_load_startpos();

    } else if (strcmp(word, "moves") == 0) {
      char move[5];

      while (fgets(move, sizeof(move), stdin)) {
        move[strcspn(move, "\n")] = 0;

        board_move_piece(move);
      }
    } else if (strcmp(word, "fen") == 0) {
      char fen[MAX_LINE];

      board_load_fen(fen);
    }
  }
}

// This is where the magic happens. Here is where we analyze possible moves to a
// given depth, and then return the best move to the front-end.
void handle_go() {
  // TODO:
  printf("bestmove b8c6\n");
  fflush(stdout);
}

void handle_quit() { running = false; }

//
// ##################
// # Main Functions #
// ##################
//

void board_load_startpos() {
  game->board->wp = 0x000000000000FF00;
  game->board->wr = 0x0000000000000081;
  game->board->wn = 0x0000000000000042;
  game->board->wb = 0x0000000000000024;
  game->board->wq = 0x0000000000000010;
  game->board->wk = 0x0000000000000008;

  game->board->bp = 0x00FF000000000000;
  game->board->br = 0x8100000000000000;
  game->board->bn = 0x4200000000000000;
  game->board->bb = 0x2400000000000000;
  game->board->bq = 0x1000000000000000;
  game->board->bk = 0x0800000000000000;
}

void board_move_piece(char *move) {}

void board_load_fen(char *fen) {}

//
// ####################
// # Bitmap Functions #
// ####################
//

// The following shows how the square variable is indexed according to the board

// Bit index:   63 ................. 0
//
// Board:
// 8  [56 57 58 59 60 61 62 63]
// 7  [48 49 50 51 52 53 54 55]
// 6  [40 41 42 43 44 45 46 47]
// 5  [32 33 34 35 36 37 38 39]
// 4  [24 25 26 27 28 29 30 31]
// 3  [16 17 18 19 20 21 22 23]
// 2  [ 8  9 10 11 12 13 14 15]
// 1  [ 0  1  2  3  4  5  6  7]
//
//      a  b  c  d  e  f  g  h

void set_bit(uint64_t *board, int square) { *board |= (1ULL << square); }

void clear_bit(uint64_t *board, int square) { *board &= ~(1ULL << square); }

void move_bit(uint64_t *board, int from, int to) {
  clear_bit(board, from);
  set_bit(board, to);
}

// ########################################

int main() {

  game = malloc(sizeof(Game));
  if (game == NULL) {
    return 1;
  }

  game->board = malloc(sizeof(Board));
  if (game->board == NULL) {
    return 1;
  }

  char line[MAX_LINE];

  while (running && fgets(line, sizeof(line), stdin)) {
    line[strcspn(line, "\n")] = 0;

    if (strcmp(line, "uci") == 0) {
      handle_uci();
    } else if (strcmp(line, "isready") == 0) {
      handle_isready();
    } else if (strncmp(line, "position", 8) == 0) {
      handle_position();
    } else if (strncmp(line, "go", 2) == 0) {
      handle_go();
    } else if (strcmp(line, "quit") == 0) {
      handle_quit();
    }
  }

  return 0;
}
