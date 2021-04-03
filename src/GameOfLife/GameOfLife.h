#ifndef _GAME_OF_LIFE_H
#define _GAME_OF_LIFE_H

#include <cstdint>
#include "GOLCell.h"
#include "Board.h"

// 30 20
class GameOfLife : Board {
    private:
        uint32_t width;
        uint32_t height;
        GOLCell board[50][50];
    public:
        GameOfLife(uint32_t w, uint32_t h);
        void updateCell(uint32_t cellX, uint32_t cellY, bool living);
        void updateAll();
};

#endif
