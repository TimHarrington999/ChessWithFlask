#include "Game.h"

Game::Game()
{
    m_board = new Board();

    m_board->loadDefaultStartPos();
}

Game::~Game()
{
    delete m_board;
    m_board = nullptr;
}

/* initial board postion functions */
void Game::loadFromStartPos()
{
    m_board->loadDefaultStartPos();
}

void Game::loadFromFen(char *fenStr)
{

}

void Game::applySingleMove(char *moveStr)
{
    
}

/* evaluate board position and determine next move */
std::string Game::getNextMove()
{
    std::string moveStr;
    


    return "b2b4";
}