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
    std::string m_chars; // for debug printing in the terminal

public:
    PieceBase(Color color);
    virtual ~PieceBase() = default;

    std::string getChars(); // for debug printing in the terminal
};