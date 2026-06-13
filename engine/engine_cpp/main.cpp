
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

#include <iostream>

#define MAX_LINE 1024
