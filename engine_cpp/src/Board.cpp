#include "Board.h"
#include "pieces/Pawn.h"

#include <memory>


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
Board::Board()
{
    // ----- Black Pieces -----

    // pawns
    auto bIt = m_board.begin() + idx(Square::A7);
    for (; bIt != m_board.begin() + idx(Square::A8); ++bIt)
    {
        *bIt = std::make_unique<Pawn>(Color::BLACK);
    }


    // ----- White Pieces -----
    
    // pawns
    auto wIt = m_board.begin() + idx(Square::A2);
    for (; wIt != m_board.begin() + idx(Square::A3); ++wIt)
    {
        *wIt = std::make_unique<Pawn>(Color::WHITE);
    }

}

void Board::loadDefaultStartPos()
{

}

void Board::movePieceFromStr(std::string moveStr)
{

}

//
// ----- Debug Functions -----
//

void Board::print()
{
    for (int i = 56; i >= 0; i -= 8)
    {
        for (int j = 0; j < 8; j++)
        {
            if (m_board[i+j] == nullptr)
            {
                printf(" __");
            }
            else
            {
                printf(" %s", m_board[i+j]->getChars().c_str());
            }
        }
        printf("\n");
    }
}