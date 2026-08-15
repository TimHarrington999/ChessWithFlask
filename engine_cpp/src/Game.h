#pragma once

#include "Board.h"
#include <string>

//typedef enum { WHITE = 0, BLACK = 1 } color;
enum class color;

class Game 
{

    color m_color;
    Board *m_board;

public:
    Game();
    ~Game();

    /* inital board position functions */
    void loadFromStartPos();
    void loadFromMoveString(char *);
    void loadFromFen(char *);

    /* evaluate board position and determine a next move */
    std::string getNextMove();
};
