#ifndef _PGEGAME_H
#define _PGEGAME_H

#include "../olcPixelGameEngine.h"

class PGEGame : public olc::PixelGameEngine {
    public:
        PGEGame();

        bool OnUserCreate() override;
        bool OnUserUpdate(float fElapsedTime) override;
};

#endif
