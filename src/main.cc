#define OLC_PGE_APPLICATION

#include <iostream>
#include "PGEGame.h"

int main(int argc, char *argv[]) {
    PGEGame pgegame(argv[1]);

    if (pgegame.Construct(128, 128, 2, 2)) {
        pgegame.Start();
    }

    return 0;
}
