#pragma once

#include "pieces/Bishop.h"
#include "pieces/King.h"
#include "pieces/Knight.h"
#include "pieces/Pawn.h"
#include "pieces/PieceBase.h"
#include "pieces/Queen.h"
#include "pieces/Rook.h"

#include "enums.h"

#include <array>
#include <memory>

class Board 
{
    std::array<std::unique_ptr<PieceBase>, 64> m_board{};

    /* helpers */
    Square StrToSquare(std::string str);

public:
    Board();

    /* functions to load an initial starting state for the board */
    void loadDefaultStartPos();
    void loadFromFen();
    void movePieceFromStr(std::string moveStr);

    /* Debug Functions */
    void print();
};
