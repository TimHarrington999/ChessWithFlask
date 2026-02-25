// Timothy's Custom Chess Engine
//
// This engine uses UCI (Universal Chess Interface) to communicate with the
// front-end.
//

//
// ## Overview ##
// This connects with Flask through the python class UCIEngine via pipe.
// Communication is first established through the handle_uci() function like a
// handshake. Flask will tell us the board position and then how far to search
// for a move.
//

#include "main.h"

#define MAX_LINE 1024

typedef enum { WHITE = 0, BLACK = 1 } color;

bool running = true;

typedef struct {
  union {
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
  } board;

  color turn;

} Game;

Game *game;

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
// 1. 'startpos'
// 2. 'startpos moves e2e4 e7e5'
// 3. 'fen <FEN>'
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

        // board_move_piece(move);
      }
    } else if (strcmp(word, "fen") == 0) {
      char fen[MAX_LINE];

      // parse fen
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

void board_load_startpos() {}

//
// ####################
// # Bitmap Functions #
// ####################
//

int main() {

  game = malloc(sizeof(Game));
  if (game == NULL) {
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
