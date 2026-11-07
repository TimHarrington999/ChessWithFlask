#pragma once

#include "Board.h"
#include "enums.h"

#include <string>


class Game 
{
    Color m_turnColor;
    std::unique_ptr<Board> m_board;

public:
    Game();

    /* inital board position functions */
    void loadFromStartPos();
    void loadFromFen(char *);
    void applySingleMove(std::string);

    /* evaluate board position and determine a next move */
    std::string getNextMove();

    /* Debug functions */
    void printBoard();
};
