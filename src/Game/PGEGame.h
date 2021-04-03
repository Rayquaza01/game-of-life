#ifndef _PGEGAME_H
#define _PGEGAME_H

#include <fstream>
#include <sstream>
#include <iomanip>
#include "../olcPixelGameEngine.h"
#include "../GameOfLife/GameOfLife.h"

class PGEGame : public olc::PixelGameEngine {
    private:
        /** width of the board */
        uint32_t width;
        /** height of the board */
        uint32_t height;

        /** Should the state automatically update? */
        bool automatic;

        /** X pos of viewport */
        uint32_t viewportX;
        /** Y pos of viewport */
        uint32_t viewportY;

        GameOfLife *board;
    public:
        PGEGame(char *fn);
        ~PGEGame();

        /** Runs on startup */
        bool OnUserCreate() override;
        /** Runs every frame */
        bool OnUserUpdate(float fElapsedTime) override;
};

#endif
