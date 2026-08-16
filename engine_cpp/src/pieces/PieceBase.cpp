# include "PieceBase.h"


PieceBase::PieceBase(Color color) :
    m_color(color)
{
    if (color == Color::WHITE)
    {
        m_chars = "w";
    }
    else
    {
        m_chars = "b";
    }
}

std::string PieceBase::Move(char *move)
{
    return nullptr;
}

//
// ----- Debug Functions -----
//

std::string PieceBase::getChars()
{
    return m_chars;
}