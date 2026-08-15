#include "Game.h"

enum class color
{
    WHITE,
    BLACK
};

Game::Game()
{
    m_board = new Board();

    m_board->load_startpos();
}

Game::~Game()
{
    delete m_board;
    m_board = nullptr;
}

/* initial board postion functions */
void Game::loadFromStartPos()
{

}

void Game::loadFromMoveString(char *moveStr)
{

}

void Game::loadFromFen(char *fenStr)
{

}

/* evaluate board position and determine next move */
std::string Game::getNextMove()
{
    std::string moveStr;
    


    return "b2b4";
}