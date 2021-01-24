#ifndef AEDA2020_PORTAGENS_HIGHWAYS_H
#define AEDA2020_PORTAGENS_HIGHWAYS_H

#include "Highway.h"

/**
 * Highway class is a class that aggregates different highways.
 *
 * Each highway's information is stored in their corresponding Highway object,
 * which is then processed in the vector 'highways' using Highways' methods.
 *
 * @param highways contains all the highways (objects from Highway class) that exist
 */
class HighwayRecord {
    vector<Highway *> highways;
public:
    /**
     * The constructor of Highways class initializes the 'highways' container as empty
     */
    HighwayRecord();

    /**
     * @return the number of highways already in the 'highways' container
     */
    int getNumHighways() const;

    /**
     * Finds and provides Highway object according to its name
     * @param name is a unique string that identifies the Highway object
     * @return the Highway object that has the name 'name' if it exists, nullptr otherwise
     */
    Highway * getHighway(string name);

    /**
     * Finds and provides Highway object according to its index
     * @param i is the index , in the vector 'highways', of the highway (Highway object)
     * @return the Highway object that has the index 'i' if it exists, nullptr otherwise
     */
    Highway * getHighwayIndex(int i);

    /**
     * Checks if Highway object with the name 'name' exists in the vector 'highways'
     * @param name is the string that a Highway object in 'highways' vector may have
     * @return false if a Highway object with name 'name' already exists in the container, true otherwise
     */
    bool checkHighwayName(string name);

    /**
     * addHighway function creates and adds a highway (that isn't already in the 'highways' container)
     * to the container 'highways', with the desired name
     * @param name is a unique string (no other highway can have the same name)
     * that will be the name of the new Highway object
     * @return false if a Highway object with the same name already exists in the 'highways' vector,
     * true otherwise (it succeeded in adding the object)
     */
    bool addHighway(string name);

    /**
     * addHighway function adds a highway (that isn't already in the 'highways' container)
     * to the container 'highways'
     * @param e is an object of Highway class to add to vector 'highways'
     * @return false if a Highway object with the same name already exists in the 'highways' vector,
     * true otherwise (it succeeded in adding the object)
     */
    void addHighway(Highway * h);

    /**
     * removeHighway function removes a highway making use of its index in the
     * vector 'highways'
     * @param i is the index, in the vector 'highways', of the Highway object to remove from the container
     * @return true if the Highway object with the index i was successfully removed from the
     * container, false otherwise
     */
    bool removeHighway(int i);

    bool checkTechnicianName(string name);
};


#endif //AEDA2020_PORTAGENS_HIGHWAYS_H
