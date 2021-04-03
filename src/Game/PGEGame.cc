#include "PGEGame.h"

PGEGame::PGEGame() {
    sAppName = "Game of Life";
}

bool PGEGame::OnUserCreate() {
    return true;
}

bool PGEGame::OnUserUpdate(float fElapsedTime) {
    return true;
}
