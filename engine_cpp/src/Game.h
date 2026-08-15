#pragma once

#include "Board.h"
#include <string>

enum class turnColor
{
    WHITE,
    BLACK
};

class Game 
{

    turnColor m_turnColor;
    Board *m_board;

public:
    Game();
    ~Game();

    /* inital board position functions */
    void loadFromStartPos();
    void loadFromFen(char *);
    void applySingleMove(char *);

    /* evaluate board position and determine a next move */
    std::string getNextMove();
};
