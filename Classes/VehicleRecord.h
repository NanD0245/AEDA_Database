#ifndef AEDA2020_PORTAGENS_VEHICLES_H
#define AEDA2020_PORTAGENS_VEHICLES_H

#include "Vehicle.h"
#include <vector>
#include <iostream>

/**
 * Vehicles class is a class that aggregates different vehicles.
 *
 * Each vehicle's information is stored in their corresponding Vehicle object,
 * which is then processed in the vector 'vehicles' using Vehicles' methods.
 *
 * @param vehicles contains all the vehicles (objects from Vehicle class) that exist
 * @param taxes contains all the different taxes for the different vehicle classes
 */
using namespace std;

class VehicleRecord {
    vector<Vehicle *> vehicles;
    float taxes[4];
public:
    /**
     * The constructor of Vehicles class initializes the 'vehicles' container as empty
     */
    VehicleRecord();

    /**
     * @return the number of vehicles already in the 'vehicles' container
     */
    int getNumVehicles() const;

    /**
     * @return the tax value corresponding to the vehicle class provided
     */
    float getTaxes(int v_class);

    /**
     * Finds and provides Vehicle object according to its plate
     * @param plate is a unique string that identifies the Vehicle object
     * @return the Vehicle object that has the plate 'plate' if it exists, nullptr otherwise
     */
    Vehicle * getVehicle(string plate);

    /**
     * Finds and provides Vehicle object according to its index
     * @param i is the index , in the vector 'vehicles', of the vehicle (Vehicle object)
     * @return the Vehicle object that has the index 'i' if it exists, nullptr otherwise
     */
    Vehicle * getVehicleIndex(int i);

    /**
     * Sets the tax for each vehicle class
     * @param a sets tax of vehicle class 1
     * @param b sets tax of vehicle class 2
     * @param c sets tax of vehicle class 3
     * @param d sets tax of vehicle class 4
     */
    void setTaxes(float a, float b, float c, float d);

    /**
     * Checks if a Vehicle object with the plate 'plate' exists in the vector 'vehicles'
     * @param plate is the string that a Vehicle object in 'vehicles' vector may have
     * @return true if a Vehicle object with plate 'plate' already exists in the container, false otherwise
     */
    bool checkPlate(string plate);

    /**
     * addVehicle function creates and adds a Vehicle object (that isn't already in the 'vehicles' container)
     * to the container 'vehicles', with the desired plate and class
     * @param plate is a unique string (no other Vehicle object can have the same name)
     * that will be the name of the new Vehicle object
     * @param v_class is a number ranging from 1 to 4 that defines the vehicle's class
     * @return false if a Vehicle object with the same plate already exists in the 'vehicles' vector,
     * true otherwise (it succeeded in adding the object)
     */
    bool addVehicle(string plate, int v_class);

    /**
     * addVehicle function creates and adds a Vehicle object (that isn't already in the 'vehicles' container)
     * to the container 'vehicles', with the desired plate, class, and green lane.
     * @param plate is a unique string (no other Vehicle object can have the same name)
     * that will be the name of the new Vehicle object
     * @param v_class is a number ranging from 1 to 4 that defines the vehicle's class
     * @param greenlane is true if the vehicle driver would rather use green lanes, false otherwise
     * @return false if a Vehicle object with the same plate already exists in the 'vehicles' vector,
     * true otherwise (it succeeded in adding the object)
     */
    bool addVehicle(string plate, int v_class, bool greenlane);

    /**
     * removeVehicle function removes a Vehicle object making use of its index in the
     * vector 'vehicles'
     * @param i is the index, in the vector 'vehicles', of the Vehicle object to remove from the container
     * @return true if the Vehicle object with the index i was successfully removed from the
     * container, false otherwise
     */
    bool removeVehicle(int i);


};

#endif //AEDA2020_PORTAGENS_VEHICLES_H
