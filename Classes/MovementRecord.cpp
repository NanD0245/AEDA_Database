#include "MovementRecord.h"

MovementRecord::MovementRecord() {movements.clear();}

int MovementRecord::getNumMovements() const {return movements.size();}

Movement * MovementRecord::getMovementIndex(int i) {
    return movements[i];
}

vector<Movement *> MovementRecord::getMovements() {return movements;}

bool MovementRecord::addMovement(Movement *m1) {
    for(size_t i = 0; i < movements.size();i++) {
        if (movements[i]->getInfo() == m1->getInfo())
            return false;
    }
    movements.push_back(m1);
    return true;
}