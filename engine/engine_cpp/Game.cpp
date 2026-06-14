#include "Game.h"
#include "Board.h"

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
}
