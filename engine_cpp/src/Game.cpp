#include "Game.h"

Game::Game()
{
    m_board = std::make_unique<Board>();
}

//
// ----- initial board postion functions -----
//
void Game::loadFromStartPos()
{
    m_board->loadDefaultStartPos();
}

void Game::loadFromFen(char *fenStr)
{
    // TODO: Implement this
}

void Game::applySingleMove(std::string moveStr)
{
    m_board->movePieceFromStr(moveStr);
}

//
// ----- evaluate board position and determine next move -----
//
std::string Game::getNextMove()
{
    std::string moveStr = "";
    
    moveStr = "d7d5";

    return moveStr;
}

//
// ----- Debug functions -----
//
void Game::printBoard()
{
    m_board->print();
}
