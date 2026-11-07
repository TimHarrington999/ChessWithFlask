#pragma once

#include "../enums.h"

#include <stdlib.h>
#include <cstring>
#include <string>

class PieceBase
{
    Color m_color;

    std::string Move(char *);

protected:
    // TODO: Name this something better
    std::string m_ColorChar; // for debug printing in the terminal

public:
    PieceBase(Color color);
    virtual ~PieceBase() = default;

    std::string getColorChar(); // for debug printing in the terminal
};
