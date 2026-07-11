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
    // TODO: Figure out why my build config doesn't like this
    //delete m_board;
}
