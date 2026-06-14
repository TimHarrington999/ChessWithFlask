#pragma once

#include "pieces/Bishop.h"
#include "pieces/King.h"
#include "pieces/Knight.h"
#include "pieces/Pawn.h"
#include "pieces/Queen.h"
#include "pieces/Rook.h"

class Board {
public:
    Board();
    ~Board();

    // initializes the setup state for a fresh round of chess
    void load_startpos();

private:

};