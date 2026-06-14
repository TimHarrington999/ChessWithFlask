
// Timothy's Custom Chess Engine
//
// This engine uses UCI (Universal Chess Interface) to communicate with the
// front-end.
//

//
// ## Overview ##
// This connects with Flask through the python class UCIEngine via pipe.
// Communication is first established through the handle_uci() function like a
// handshake
// Flask will tell us the board position and then how far to search for a move
//
// This will merely serve as an entry point/UCI logic for the rest of the cpp engine.
//

#include "main.h"
#include "Game.h"

#include <cstring>
#include <stdlib.h>
#include <stdio.h>

#define MAX_LINE 1024

bool running = true;

Game *theGame = new Game(); // TODO: Make not global loool


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
      theGame->load_startpos();

    } else if (strcmp(word, "moves") == 0) {
      char move[5];

      while (fgets(move, sizeof(move), stdin)) {
        move[strcspn(move, "\n")] = 0;

        theGame->move_piece(move);
      }
    } else if (strcmp(word, "fen") == 0) {
      char fen[MAX_LINE];

      theGame->load_fen(fen);
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


// ######################
// # Engine Entry Point #
// ######################


int main() {

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