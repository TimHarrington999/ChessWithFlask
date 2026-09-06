#include "Board.h"
#include "pieces/Bishop.h"
#include "pieces/Pawn.h"

#include <memory>


Board::Board()
{
}

// #####
// ##### Functions for loading starting position #####
// #####

void Board::loadDefaultStartPos()
{
    //
    // ----- Black Pieces -----
    //

    // pawns
    auto bIt = m_board.begin() + idx(Square::A7);
    for (; bIt != m_board.begin() + idx(Square::A8); ++bIt)
    {
        *bIt = std::make_unique<Pawn>(Color::BLACK);
    }

    // rooks
    m_board[idx(Square::A8)] = std::make_unique<Rook>(Color::BLACK);
    m_board[idx(Square::H8)] = std::make_unique<Rook>(Color::BLACK);

    // knights
    m_board[idx(Square::B8)] = std::make_unique<Knight>(Color::BLACK);
    m_board[idx(Square::G8)] = std::make_unique<Knight>(Color::BLACK);

    // bishops
    m_board[idx(Square::C8)] = std::make_unique<Bishop>(Color::BLACK);
    m_board[idx(Square::F8)] = std::make_unique<Bishop>(Color::BLACK);

    // queen
    m_board[idx(Square::D8)] = std::make_unique<Queen>(Color::BLACK);

    // king
    m_board[idx(Square::E8)] = std::make_unique<King>(Color::BLACK);


    //
    // ----- White Pieces -----
    //

    // pawns
    auto wIt = m_board.begin() + idx(Square::A2);
    for (; wIt != m_board.begin() + idx(Square::A3); ++wIt)
    {
        *wIt = std::make_unique<Pawn>(Color::WHITE);
    }

    // rooks
    m_board[idx(Square::A1)] = std::make_unique<Rook>(Color::WHITE);
    m_board[idx(Square::H1)] = std::make_unique<Rook>(Color::WHITE);

    // knights
    m_board[idx(Square::B1)] = std::make_unique<Knight>(Color::WHITE);
    m_board[idx(Square::G1)] = std::make_unique<Knight>(Color::WHITE);

    // bishops
    m_board[idx(Square::C1)] = std::make_unique<Bishop>(Color::WHITE);
    m_board[idx(Square::F1)] = std::make_unique<Bishop>(Color::WHITE);

    // queen
    m_board[idx(Square::D1)] = std::make_unique<Queen>(Color::WHITE);

    // king
    m_board[idx(Square::E1)] = std::make_unique<King>(Color::WHITE);
}

void Board::loadFromFen()
{
    // TODO: implement this
}

// only for setting an initial position given from the flask side
void Board::movePieceFromStr(std::string moveStr)
{
    Square from = StrToSquare(moveStr.substr(0, 2));
    Square to = StrToSquare(moveStr.substr(2,2));

    if (m_board[idx(from)] != nullptr)
    {
        m_board[idx(to)] = std::move(m_board[idx(from)]);
    }
    else
    {
        // Maybe Todo?
        // This would mean that flask sent an invalid move string for setup
    }

}

// #####
// ##### Helpers #####
// #####

Square Board::StrToSquare(std::string str)
{
    size_t file = str[0] - 'a';
    size_t rank = str[1] - '1';

    return static_cast<Square>(rank * 8 + file);
}



// #####
// ##### Debug Functions #####
// #####

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