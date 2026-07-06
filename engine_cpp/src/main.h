// For now, the main UCI functions won't be in a class for simplicity

#pragma once

#include "Game.h"


/* UCI Functions */
void handle_uci();
void handle_isready();
void handle_position();
void handle_quit();