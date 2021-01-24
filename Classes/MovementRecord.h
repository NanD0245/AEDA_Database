#ifndef AEDA2020_PORTAGENS_MOVEMENTS_H
#define AEDA2020_PORTAGENS_MOVEMENTS_H

#include "Movement.h"
#include <vector>

using namespace std;


/**
 * Movements class is a class that aggregates different Movement objects.
 *
 * Each movement's information is stored in their corresponding Movement object,
 * which is then processed in the vector 'movements' using Movements' methods.
 *
 * @param movements contains all the movements (objects from Movements class) that exist
 */
class MovementRecord {
    vector<Movement *> movements;
public:
    /**
     * The constructor of Movements class initializes the 'highways' container as empty
     */
    MovementRecord();

    /**
     * @return the number of movements already in the 'movements' container
     */
    int getNumMovements() const;

    /**
     * Finds and provides Movement object according to its index
     * @param i is the index , in the vector 'movements', of the movement (Movement object)
     * @return the Movement object that has the index 'i'
     */
    Movement * getMovementIndex(int i);

    /**
     * @return 'movements' attribute
     */
    vector<Movement *> getMovements();

    /**
     * addMovement function adds a movement (that isn't already in the 'movement' container)
     * to the container 'movements'
     * @param e is an object of Movement class to add to vector 'movements'
     * @return false if a  object with the same information (given by Movement method getInfo())
     * already exists in the 'movements' vector, true otherwise (it succeeded in adding the object)
     */
    bool addMovement(Movement* m1);
    //void ordenarData()
};


#endif //AEDA2020_PORTAGENS_MOVEMENTS_H
