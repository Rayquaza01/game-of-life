#include "GameOfLife.h"
#include "GOLCellStateChange.h"

GameOfLife::GameOfLife(uint32_t w, uint32_t h) {
    width = w;
    height = h;
}

void GameOfLife::updateCell(uint32_t x, uint32_t y, bool living) {
    if (x >= 0 && x <= width && y >= 0 && y <= height) {
        board[y][x].forceNextState(living);
        GOLCellStateChange stateChange = board[y][x].commit();

        if (stateChange != GOLCellStateChange::NO_CHANGE) {
            Position current;
            current.x = x;
            current.y = y;
            for (uint32_t d = 0; d < 8; d++) {
                Position newPos;

                bool adj = findAdjacent(current, newPos, d, false);
                if (adj) {
                    board[newPos.y][newPos.x].neighborUpdate(stateChange);
                }
            }
        }
    }
}

void GameOfLife::updateAll() {
    for (uint32_t i = 0; i < height; i++) {
        for (uint32_t j = 0; j < width; j++) {
            board[i][j].update();
        }
    }

    for (uint32_t i = 0; i < height; i++) {
        for (uint32_t j = 0; j < width; j++) {
            GOLCellStateChange stateChange = board[i][j].commit();

            if (stateChange != GOLCellStateChange::NO_CHANGE) {
                Position current;
                current.x = j;
                current.y = i;
                for (uint32_t d = 0; d < 8; d++) {
                    Position newPos;

                    bool adj = findAdjacent(current, newPos, d, false);
                    if (adj) {
                        board[newPos.y][newPos.x].neighborUpdate(stateChange);
                    }
                }
            }
        }
    }
}
