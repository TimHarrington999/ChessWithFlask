#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// UCI Functions
void handle_uci();
void handle_isready();
void handle_position();
void handle_go();
void handle_quit();

// Main Functions
void board_load_startpos();

// Bitmap Functions
