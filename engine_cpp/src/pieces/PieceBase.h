#pragma once

#include "../enums.h"

#include <stdlib.h>
#include <cstring>
#include <string>

class PieceBase
{
    TurnColor m_color;


    std::string Move(char *);

public:
    PieceBase(TurnColor color);
    virtual ~PieceBase() = default;


};