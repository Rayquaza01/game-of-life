#ifndef _PGEGAME_H
#define _PGEGAME_H

#include <fstream>
#include "../olcPixelGameEngine.h"
#include "../GameOfLife/GameOfLife.h"

class PGEGame : public olc::PixelGameEngine {
    private:
        uint32_t width;
        uint32_t height;

        GameOfLife *board;
    public:
        PGEGame(char *fn);
        ~PGEGame();

        bool OnUserCreate() override;
        bool OnUserUpdate(float fElapsedTime) override;
};

#endif
