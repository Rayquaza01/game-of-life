#define OLC_PGE_APPLICATION

#include <iostream>
#include "PGEGame.h"

int main(int argc, char *argv[]) {
    PGEGame pgegame(argv[1]);

    if (pgegame.Construct(64, 64, 4, 4)) {
        pgegame.Start();
    }

    return 0;
}
