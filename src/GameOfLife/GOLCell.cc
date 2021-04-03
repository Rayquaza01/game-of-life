#include "GOLCell.h"

GOLCell::GOLCell() {
    nextState = false;
    currentState = 0;
    livingNeighbors = 0;
}

bool GOLCell::isAlive() {
    return currentState & 1;
}

void GOLCell::update() {
    bool isLiving = isAlive();

    if (isLiving) {
        if (livingNeighbors == 2 || livingNeighbors == 3) {
            nextState = true;
        } else {
            nextState = false;
        }
    } else {
        if (livingNeighbors == 3) {
            nextState = true;
        } else {
            nextState = false;
        }
    }
}

GOLCellStateChange GOLCell::commit() {
    bool isLiving = isAlive();

    currentState = (currentState << 1) | nextState;

    if (nextState == isLiving) {
        return GOLCellStateChange::NO_CHANGE;
    } else if (nextState && !isLiving) {
        return GOLCellStateChange::LIVING;
    } else if (!nextState && isLiving) {
        return GOLCellStateChange::DEAD;
    }

    return GOLCellStateChange::NO_CHANGE;
}

void GOLCell::neighborUpdate(GOLCellStateChange n) {
    switch (n) {
        case GOLCellStateChange::LIVING:
            livingNeighbors++;
            break;
        case GOLCellStateChange::DEAD:
            livingNeighbors--;
            break;
    }
}

void GOLCell::forceNextState(bool living) {
    nextState = living;
}
