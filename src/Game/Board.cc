#include "Board.h"

Board::Board(uint32_t w, uint32_t h) {
    width = w;
    height = h;
}

bool Board::findAdjacent(Position p, Position &newp, uint32_t dir, bool wrap) {
    newp.x = p.x + dX[dir];
    newp.y = p.y + dY[dir];

    if (newp.y >= height || newp.y < 0 || newp.x >= width || newp.x < 0) {
        if (wrap) {
            newp.x = newp.x % width;
            newp.y = newp.y % height;
        } else {
            return false;
        }
    }

    return true;
}
