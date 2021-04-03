#include "PGEGame.h"

PGEGame::PGEGame(char* fn) {
    sAppName = "Game of Life";

    automatic = false;
    viewportX = 0;
    viewportY = 0;

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
        width = 1000;
        height = 1000;

        board = new GameOfLife(1000, 1000);
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
    Clear(olc::BLACK);

    std::stringstream xPos;
    std::stringstream yPos;
    xPos << std::setw(3) << std::to_string(viewportX);
    yPos << std::setw(3) << std::to_string(viewportY);
    DrawString(0, 0, xPos.str(), olc::WHITE, 1);
    DrawString(32, 0, yPos.str(), olc::WHITE, 1);

    for (uint32_t i = 0; i < std::min(height, 54U); i++) {
        for (uint32_t j = 0; j < std::min(width, 64U); j++) {
            uint32_t cellX = viewportX + j;
            uint32_t cellY = viewportY + i;
            if (cellX >= 0 && cellX < width && cellY >= 0 && cellY < height) {
                if (board->getCell(viewportX + j, viewportY + i)) {
                    Draw(j, 10 + i, olc::Pixel(0, 255, 0));
                } else {
                    Draw(j, 10 + i, olc::Pixel(255, 0, 0));
                }
            } else {
                Draw(j, 10 + i, olc::Pixel(0, 0, 0));
            }
        }
    }

    if (GetKey(olc::Key::RIGHT).bHeld) {
        viewportX++;
        if (viewportX > width) viewportX = width;
    }
    if (GetKey(olc::Key::LEFT).bHeld) {
        viewportX--;
        if (viewportX > width) viewportX = 0;
    }
    if (GetKey(olc::Key::DOWN).bHeld) {
        viewportY++;
        if (viewportY > height) viewportY = height;
    }
    if (GetKey(olc::Key::UP).bHeld) {
        viewportY--;
        if (viewportY > height) viewportY = 0;
    }

    if (GetKey(olc::ENTER).bPressed || automatic) {
        board->updateAll();
    }

    if (GetKey(olc::SPACE).bPressed) {
        automatic = !automatic;
    }

    if (GetMouse(0).bPressed) {
        uint32_t mouseX;
        uint32_t mouseY;

        mouseX = viewportX + GetMouseX();
        mouseY = viewportY + GetMouseY() - 10;

        if (mouseY < 1000) {
            board->updateCell(mouseX, mouseY, !board->getCell(mouseX, mouseY));
        }
    }

    return true;
}
