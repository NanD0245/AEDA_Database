//
// Created by mim on 15/12/20.
//

#ifndef AEDA2020_PORTAGENS_ONWERS_H
#define AEDA2020_PORTAGENS_ONWERS_H

#include <unordered_set>
#include "Vehicle.h"
#include "Owner.h"

struct ownerHash
{
    int operator() (const Owner& o1) const
    {
        int v = 0;
        for (char i: o1.getName())
            v = 37*v + i;
        return v;
    }

    bool operator() (const Owner& o1, const Owner& o2) const
    {
        return o1.getName() == o2.getName();
    }
};

class OwnerRecord {
    unordered_set<Owner,ownerHash,ownerHash> owners;
public:
    /**
     * Clears the owners container
     */
    OwnerRecord();

    /**
     * Adds an owner to the owners container as long as there isn't one with the same name already
     * @param name is the attribute 'name' of the owner to add
     * @return true if there wasn't another object with the same name, false otherwise
     */
    bool addOwner(string name);

    /**
     * Adds an Owner object to the owners container
     * @param o is the Owner object to add
     * @return true if it was able to add, false otherwise
     */
    bool addOwner(Owner o);

    /**
     * Removes the selected Owner object from the container
     * @param o1  is the Owner object to remove
     * @return true if it is able to erase the object, false otherwise
     */
    bool deleteOwner(Owner o1);

    /**
     * Finds an Owner object according to it's index in the unordered set
     * @param index is the index in the container of the object to select
     * @return Owner object selected
     */
    Owner getOwner(int index);

    /**
     * @return the number of owners there are
     */
    int getNumOwners() const;

    /**
     * @return a vector with strings that represent all the owners and their info
     */
    vector<string> showOwners();

    /**
     * Adds vehicle provided to the owner with the name 'name'
     * @param name is the owner's name attribute
     * @param vehicle is the vehicle to add to the owner
     * @return true if it was able to add the vehicle to the owner, false otherwise
     */
    bool addVehicleOwner(string name, Vehicle* vehicle);

    /**
     * Checks if the Owner has a vehicle with the plate 'plate'
     * @param plate is the attribute 'plate' to compare to
     * @return true if it found a vehicle with the same plate as the one provided, false otherwise
     */
    bool checkPlate(string plate);

    /**
     * @return owners container
     */
    unordered_set<Owner,ownerHash,ownerHash> getOwners() const;
};


#endif //AEDA2020_PORTAGENS_ONWERS_H
