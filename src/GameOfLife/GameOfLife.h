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
        /**
         * @param w The width of the board
         * @param h THe height of the board
         */
        GameOfLife(uint32_t w, uint32_t h);

        ~GameOfLife();

        /**
         * Updates a cell to the given state
         * @param cellX X pos of relavent cell
         * @param cellY Y pos of relavent cell
         * @param living The state to set the cell to
         */
        void updateCell(uint32_t cellX, uint32_t cellY, bool living);

        /** Updates every cell to the next state */
        void updateAll();

        /**
         * Find the position of an adjacent cell
         * @param p The position of the current cell
         * @param newp The position of the new cell (reference)
         * @param dir The direction of the adjacent cell
         * @param wrap Should the cursor wrap?
         */
        bool findAdjacent(Position p, Position &newp, uint32_t dir, bool wrap);

        /**
         * Get the state of a cell
         * @param cellX X pos of relavent cell
         * @param cellY Y pos of relavent cell
         */
        bool getCell(uint32_t cellX, uint32_t cellY);
};

#endif
