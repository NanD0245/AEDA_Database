//
// Created by mim on 15/12/20.
//

#ifndef DATE_CPP_OWNER_H
#define DATE_CPP_OWNER_H

#include <string>
#include <vector>
#include "Vehicle.h"

using namespace std;

class Owner {
    string name;
    vector<Vehicle*> vehicles;
public:

    /**
     * Creates a new Owner object with the name 'name' and with no vehicles
     * @param name sets 'name'
     */
    Owner(string name);

    /**
     *
     * @return 'name' attribute
     */
    string getName() const;

    /**
     *
     * @param name sets 'name'
     */
    void setName(string name);

    /**
     *
     * @return the number of Vehicles an Owner has
     */
    int getNumVehicles() const;

    /**
     * Adds object of class Vehicle to the ownership of current Owner object
     * @param vehicle is a Vehicle object
     * @return true if it was able to add the object, false otherwise
     */
    bool addVehicle(Vehicle* vehicle);

    /**
     * Creates and adds an object of class Vehicle with the provided parameters
     * @param plate is the 'plate' of the Vehicle object to create
     * @param v_class is the vehicle class of the Vehicle object to create
     * @param tax is the 'tax' of the Vehicle object to create
     * @return true if it was able to, false otherwise
     */
    bool addVehicle(string plate, int v_class, float tax);

    /**
     * Removes a Vehicle with the plate 'plate' from the Owner's possession
     * @param plate is the attribute 'plate' of the vehicle
     * @return true if it was able to, false otherwise
     */
    bool deleteVehicle(string plate);

    /**
     * Removes a Vehicle by its index in the container vehicles
     * @param index is the index in the container vehicles
     * @return true if it was able to, false otherwise
     */
    bool deleteVehicle(int index);

    /**
     * @return the vector which contains all vehicles that belong to an Owner
     */
    vector<Vehicle*> getVehicles();

    /**
     * @return a vector of strings about all the vehicles that belong to an Owner, providing information about those vehicles
     */
    vector<string> showVehicles();

    /**
     * Overloads the == operator to be able to compare different Owner objects
     * @param o1 is the object to compare the current Owner object to
     * @return true if they have the same name, false otherwise
     */
    bool operator==(const Owner& o1);

    /**
     * @return string with the Owner's name and its vehicles
     */
    string getInfo() const;
};


#endif //DATE_CPP_OWNER_H
