#ifndef AEDA2020_PORTAGENS_HIGHWAY_H
#define AEDA2020_PORTAGENS_HIGHWAY_H

#include "Toll.h"



/**
 * Highway class is a class that aggregates different tolls.
 *
 * Each toll's information is stored in their corresponding Toll object,
 * which is then processed in the vector 'tolls' using Highway's methods.
 *
 * @param tolls contains all the tolls (objects from 'Toll' class) that belong to this Highway
 * @param name is a unique string (other objects can't have the same name)
 */
class Highway {
    vector<Toll *> tolls;
    string name;
public:
    /**
     * Constructor of Highway Class
     * @param name is the Highway's name
     */
    Highway(string name);

    /**
     * @return integer that is the number of total tolls in current Highway
     */
    int getNumTolls() const;

    /**
     * Finds and provides Toll object according to its name
     * @param name is the string that identifies the Toll object to find
     * @return the Toll object that has the name 'name' if it exists, nullptr otherwise
     */
    Toll * getToll(string name);

    /**
     * Finds and provides Toll object according to its index
     * @param i is the index , in the vector 'tolls', of the Toll object
     * @return the Toll object that has the index 'i' if it exists, nullptr otherwise
     */
    Toll * getTollIndex(int i);

    /**
     * @return string with Highway's name
     */
    string getInfo() const;

    /**
     * @return string in the format: "Highway Name: " + name
     */
    string showHighway() const;

    /**
     * @param new_name updates the Highway's name to desired new name
     */
    void setName(int highway_id, string new_name);

    /**
     * addToll function creates and adds a toll (that isn't already in the 'tolls' container)
     * @param name is a unique string that will be the name of the toll to be added
     * @param geolocal is a string that gives information about the toll's location
     * @param highway_kilometer is the kilometer in the highway where the toll is situated
     * @param type is true when the toll is an exit and false when it is an entrance
     * @return false when the toll already exists in the 'tolls' container,
     * true otherwise (succeeded in adding the object)
     */

    bool addToll(string name, string geolocal, float highway_kilometer,bool type);

    /**
     * addToll function adds a toll (that isn't already in the 'tolls' container)
     * @param t is the toll (Toll object) to be added
     * @return false when the toll already exists in the 'tolls' container,
     * true otherwise (succeeded in adding the object)
     */
    bool addToll(Toll *t);

    /**
     * removeToll function removes a toll making use of its index in the
     * vector 'tolls'
     * @param i is the index, in the vector 'tolls', of the toll to remove from the container
     * @return false if a Toll with the same name already exists in the 'tolls' vector,
     * true otherwise (it succeeded in adding the object)
     */
    bool removeToll(Toll * t1);

    /**
     * removeToll function removes a toll making use of its index in the
     * vector 'tolls'
     * @param i is the index, in the vector 'tolls', of the toll to remove from the container
     * @return false if 'i' is bigger than the size of vector 'tolls'
     */
    bool removeToll(int i);

    /**
     * Checks if Toll with the name 'name' exists in the vector 'tolls'
     * @param name is the string that a Toll object in 'tolls' vector may have
     * @return false if a Toll with name 'name' already exists, true otherwise
     */
    bool checkTollName(string name);

    /**
     * @brief Overloads the '==' operator to be able to know if two different Highways are the same
     * @param l2 is the object of class Highway to compare the current object to
     * @return true if both Highways have the same 'name', false otherwise
     */
    bool operator==(const Highway &l2);
    
    /**
     * Checks if there's Technician with name 'name'
     * @param name is 'name' attribute
     * @return false if it found one, true otherwise
     */
    bool checkTechnicianName(string name);
    /**
     * Finds Technician according to its name
     * @param name of the Technician to find
     * @return Technician object if it was found, nullptr otherwise
     */
    Technician* getTechnicianName(string name);
    /**
     * @brief Returns a vector sorted by highest Distance
     * @param toll is the object of class Toll
     * @return true if both Highways have the same 'name', false otherwise
     */
    vector<Toll*> sortTollDistance(Toll* toll);
};


#endif //AEDA2020_PORTAGENS_HIGHWAY_H
