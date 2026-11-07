# include "PieceBase.h"


PieceBase::PieceBase(Color color) :
    m_color(color)
{
    if (color == Color::WHITE)
    {
        m_ColorChar = "w";
    }
    else
    {
        m_ColorChar = "b";
    }
}

std::string PieceBase::Move(char *move)
{
    return nullptr;
}

//
// ----- Debug Functions -----
//

std::string PieceBase::getColorChar()
{
    return m_ColorChar;
}
