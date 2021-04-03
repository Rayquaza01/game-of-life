#ifndef _GOLCELL_H
#define _GOLCELL_H

#include <cstdint>
#include "GOLCellStateChange.h"

class GOLCell {
    private:
        bool nextState;
        uint32_t currentState;
        uint32_t livingNeighbors;
    public:
        GOLCell();
        void update();
        GOLCellStateChange commit();
        bool isAlive();
        void neighborUpdate(GOLCellStateChange n);

        void forceNextState(bool living);
};

#endif
