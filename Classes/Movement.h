#ifndef AEDA2020_PORTAGENS_MOVEMENT_H
#define AEDA2020_PORTAGENS_MOVEMENT_H

#include "Vehicle.h"
#include "HighwayRecord.h"
#include "Date.h"
#include <cmath>

/**
 * The class Movement is a class that has information about each
 * and every movement made by vehicles between Highways, Tolls and Lanes
 *
 *
 * @param type tells if it is an exit movement (leaving a Toll) if it's true or entrance (entering a Toll) if it's false
 * @param vehicle is the Vehicle object that made the movement
 * @param highway is the Highway object in which the movement was made
 * @param toll is the Toll object that the vehicle passed by when it made the movement
 * @param lane is the Lane object that the vehicle was in when it made the movement
 * @param date was the moment when the vehicle made the movement
 */
class Movement {
protected:
    bool type;
    Vehicle* vehicle;
    Highway* highway;
    Toll* toll;
    Lane* lane;
    Date* date;
public:
    /**
     * Initializes a new Movement object with the input provided by the user and sets type to false
     * @param vehicle1 sets 'vehicle' attribute
     * @param highway1 sets 'highway' attribute
     * @param toll1 sets 'toll' attribute
     * @param lane1 sets 'lane' attribute
     * @param date sets 'date' attribute
     */
    Movement(Vehicle* vehicle1, Highway* highway1, Toll* toll1, Lane* lane1, Date *date);

    /**
     * @return 'type' attribute
     */
    bool getType() const;

    /**
     * @return 'vehicle' attribute
     */
    Vehicle * getVehicle() const;

    /**
     * @return 'highway' attribute
     */
    Highway * getHighway() const;

    /**
     * @return 'toll' attribute
     */
    Toll * getToll() const;

    /**
     * @return 'lane' attribute
     */
    Lane * getLane() const;

    /**
     * @return 'date' attribute
     */
    Date * getDate() const;

    /**
     * @return string in the following format:
     * date->getInfo() + " - " + highway->getInfo() + " - " + toll->getName()+ " - " + lane->getLaneNumber()+ " - " + vehicle->getPlate()
     */
    virtual string getInfo() const;
    virtual float getDistance() const;
    virtual float getPrice() const;

    /**
     * @return string in the following format:
     * date->getInfo() + " - Movement Type: " + type + " - Highway Name: " + highway->getInfo() +
           " - Toll Name: " + toll->getName() + " - Lane Number: " + lane->getLaneNumber() + " - Vehicle Plate: " + vehicle->getPlate()
     */
    virtual string showMovement() const;
};


/**
 * The class MovementEntrance is a class derived publicly from Movement class.
 * It has information about a Movement that is an entrance.
 *
 */
class MovementEntry : public Movement {
public:
    /**
     * Initializes a new MovementEntrance object with the input provided by the user
     * @param vehicle1 sets 'vehicle' attribute
     * @param highway1 sets 'highway' attribute
     * @param toll1 sets 'toll' attribute
     * @param lane1 sets 'lane' attribute
     * @param date sets 'date' attribute
     */
    MovementEntry(Vehicle* vehicle1, Highway* highway1, Toll* toll1, Lane* lane1, Date* date);

    /**
     * @return string as implemented in Movement method getInfo()
     */
    string getInfo() const;

    /**
     * @return string as implemented in Movement method showMovement()
     */
    string showMovement() const;
    //bool operator==(const MovementEntry &m1);
};


/**
 * The class MovementOut is a class derived publicly from Movement class.
 * It has information about a Movement that is an exit.
 *
 * @param entry is a Movement object that gives information about the previous movement of that vehicle (an entry movement)
 * @param distance is the distance between the last toll (an entrance toll) and the current toll (an exit toll)
 * @param price is the price that the vehicle driver has to pay to exit the toll, calculated using travelled distance and the vehicle's tax
 */
class MovementOut : public Movement {
    Movement * entry;
    float distance;
    float price;
public:
    /**
     * Initializes a new MovementOut object with the input provided by the user
     * @param vehicle1 sets 'vehicle' attribute
     * @param highway1 sets 'highway' attribute
     * @param toll1 sets 'toll' attribute
     * @param lane1 sets 'lane' attribute
     * @param date sets 'date' attribute
     * @param entry sets 'entry' attribute
     */
    MovementOut(Vehicle* vehicle1, Highway* highway1, Toll* toll1, Lane* lane1, Date* date, Movement * entry);

    /**
     * Initializes a new MovementOut object with the input provided by the user
     * @param vehicle1 sets 'vehicle' attribute
     * @param highway1 sets 'highway' attribute
     * @param toll1 sets 'toll' attribute
     * @param lane1 sets 'lane' attribute
     * @param date sets 'date' attribute
     * @param entry sets 'entry' attribute
     * @param price sets 'price' attribute
     */
    MovementOut(Vehicle* vehicle1, Highway* highway1, Toll* toll1, Lane* lane1, Date* date, Movement * entry, float price);

    /**
     * @return 'distance' attribute
     */
    float getDistance() const;

    /**
     * @return 'price' attribute
     */
    float getPrice() const;

    /**
     * @return string in the following format:
     * Movement::getInfo() + " - " + distance + " - " + price + " - " + entry->getInfo()
     */
    string getInfo() const;

    /**
     * @return string in the following format:
     * Movement::showMovement() + " - Distance: " + distance + " - Price: " + price + "\n\t\t" + "Entry Movement: " + entry->showMovement()
     */
    string showMovement() const;
};

#endif //AEDA2020_PORTAGENS_MOVEMENT_H