
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

#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>

#define MAX_LINE 1024 // TODO: Make better

// debug flag. for running the engine directly in the terminal for testing
bool is_debug = false;

bool running = true;

Game *theGame = new Game(); // TODO: Make not global loool


// There are three possibilities when handling position
// 1. (Just the start position) - 'startpos'
// 2. (start position and a move sequence) - 'startpos moves e2e4 e7e5'
// 3. (FEN string) - 'fen <FEN>'




// ######################
// # Engine Entry Point #
// ######################


int main(int argc, char* argv[]) {

    if (argc == 2)
    {
        if (strcmp(argv[1], "-debug") == 0)
        {
            is_debug = true;
            printf("Running in debug mode!\n");
        }
    }

    std::string line;

    // TODO: Add better error handling, logic is pretty fragile as-is
    while (running && std::getline(std::cin, line))
    {
        std::istringstream input(line);

        std::string word;
        input >> word;

        if (word == "uci")
        {
            printf("id name TimothyChessEngine\n");
            printf("id author TimothyHarrington\n");
            printf("uciok\n");
            fflush(stdout);
        }
        else if (word == "isready")
        {
            printf("readyok\n");
            fflush(stdout);
        }
        else if (word == "position")
        {
            input >> word; // grab next word in line
            if (word == "fen")
            {
                //theGame->loadFromFen();
                continue;
            }
            else if (word == "startpos")
            {
                theGame->loadFromStartPos();
                input >> word; // word 'moves' may come next
            }
            
            if (word == "moves")
            {
                while (input >> word)
                {
                    // grab and apply next move until there are no more
                    theGame->applySingleMove(word);
                }
            }
        }
        else if (word == "go")
        {
            // TODO: implement
            std::string moveStr = theGame->getNextMove();

            printf("bestmove %s\n", moveStr.c_str());

            //printf("bestmove b8c6\n");
            fflush(stdout);
        }
        else if (word == "quit")
        {
            running = false;
        }

        // ----- Non UCI functionality, for debug purposes -----
        else if (is_debug && word == "print")
        {
            theGame->printBoard();
        }
    }

    delete theGame;
    return 0;
}