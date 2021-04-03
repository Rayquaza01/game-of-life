#ifndef _GAME_OF_LIFE_H
#define _GAME_OF_LIFE_H

#include <cstdint>
#include "GOLCell.h"

const int32_t dX[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int32_t dY[] = {-1, -1, 0, 1, 1, 1, 0, -1};

struct Position {
    int32_t x;
    int32_t y;
};

// 30 20
class GameOfLife {
    private:
        uint32_t width;
        uint32_t height;
        GOLCell **board;
    public:
        GameOfLife(uint32_t w, uint32_t h);
        ~GameOfLife();
        void updateCell(uint32_t cellX, uint32_t cellY, bool living);
        void updateAll();
        bool findAdjacent(Position p, Position &newp, uint32_t dir, bool wrap);
        bool getCell(uint32_t cellX, uint32_t cellY);
};

#endif
