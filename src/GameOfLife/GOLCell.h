#ifndef _GOLCELL_H
#define _GOLCELL_H

#include <cstdint>
#include "GOLCellStateChange.h"

class GOLCell {
    private:
        /** The state the cell will be in next cycle */
        bool nextState;
        /** The current state. (Also contains previous states) */
        uint32_t currentState;
        /** Number of living neighbors */
        uint32_t livingNeighbors;
    public:
        GOLCell();

        /** Calculate what the next state is */
        void update();

        /** Add the next state to the current state */
        GOLCellStateChange commit();

        /** Get the current state */
        bool isAlive();

        /**
         * Called when a neighbor updates. Updates the number of living neighbors.
         * @param n The state change of the neighbor
         */
        void neighborUpdate(GOLCellStateChange n);

        /**
         * Force the next state
         * Used to set the initial condition of the simulation
         * @param living The state to set the cell to
         */
        void forceNextState(bool living);
};

#endif
