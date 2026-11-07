#include "Pawn.h"

Pawn::Pawn(Color color) :
    PieceBase(color)
{
    m_ColorChar += "p";
}
