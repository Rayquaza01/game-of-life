#ifndef _BOARD_H
#define _BOARD_H

#include <cstdint>

int32_t dX[] = {0, 1, 1, 1, 0, -1, -1, -1};
int32_t dY[] = {-1, -1, 0, 1, 1, 1, 0, -1};

struct Position {
    int32_t x;
    int32_t y;
};

class Board {
    private:
        uint32_t width;
        uint32_t height;
    public:
        Board(uint32_t w, uint32_t h);
        bool findAdjacent(Position p, Position &newp, uint32_t dir, bool wrap);
};

#endif
