#include "PGEGame.h"

PGEGame::PGEGame(char* fn) {
    sAppName = "Game of Life";

    std::ifstream file;
    file.open(fn, std::fstream::in);

    if (file.is_open()) {
        file >> width >> height;

        board = new GameOfLife(width, height);

        for (uint32_t i = 0; i < height; i++) {
            for (uint32_t j = 0; j < width; j++) {
                char cell;
                file >> cell;

                switch (cell) {
                    case '1':
                        board->updateCell(j, i, true);
                        break;
                    case '0':
                        board->updateCell(j, i, false);
                        break;
                }
            }
        }
    } else {
        width = 10;
        height = 10;

        board = new GameOfLife(10, 10);
    }

    file.close();
}

PGEGame::~PGEGame() {
    delete board;
}

bool PGEGame::OnUserCreate() {
    return true;
}

bool PGEGame::OnUserUpdate(float fElapsedTime) {
    for (uint32_t i = 0; i < height; i++) {
        for (uint32_t j = 0; j < width; j++) {
            if (board->getCell(j, i)) {
                Draw(j, i, olc::Pixel(0, 255, 0));
            } else {
                Draw(j, i, olc::Pixel(255, 0, 0));
            }
        }
    }

    board->updateAll();

    return true;
}
