#pragma once

#include "pieces/Bishop.h"
#include "pieces/King.h"
#include "pieces/Knight.h"
#include "pieces/Pawn.h"
#include "pieces/Queen.h"
#include "pieces/Rook.h"

class Board 
{

    // This is how the index to the board lays out
    // Bit index:   63 ................. 0
    //
    // Board:
    // 8  [56 57 58 59 60 61 62 63]
    // 7  [48 49 50 51 52 53 54 55]
    // 6  [40 41 42 43 44 45 46 47]
    // 5  [32 33 34 35 36 37 38 39]
    // 4  [24 25 26 27 28 29 30 31]
    // 3  [16 17 18 19 20 21 22 23]
    // 2  [ 8  9 10 11 12 13 14 15]
    // 1  [ 0  1  2  3  4  5  6  7]
    //
    //      a  b  c  d  e  f  g  h
    //
    PieceBase m_board[64];

    

public:
    Board();

    /* functions to load an initial starting state for the board */
    void loadDefaultStartPos();
    void loadFromFen();

    /* single move functions */

    // takes a standard move string, ie b2b4 and applies it
    void movePieceFromStr(std::string moveStr);
};
