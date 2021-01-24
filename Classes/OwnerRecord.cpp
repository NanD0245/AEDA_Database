//
// Created by mim on 15/12/20.
//

#include "OwnerRecord.h"

OwnerRecord::OwnerRecord() {owners.clear(); }

int OwnerRecord::getNumOwners() const {return owners.size(); }

bool OwnerRecord::addOwner(string name) {
    for (const auto & owner : owners)
        if (owner.getName() == name) return false;
    auto a = owners.insert(Owner(name));
    if (get<1>(a))
        return true;
    return false;
}

bool OwnerRecord::addOwner(Owner o){
    auto a = owners.insert(o);
    if (get<1>(a))
        return true;
    return false;
}

unordered_set<Owner,ownerHash,ownerHash> OwnerRecord::getOwners() const{return owners;}

bool OwnerRecord::addVehicleOwner(string name, Vehicle *vehicle) {
    Owner a("");
    for (auto it = owners.begin(); it != owners.end(); it++) {
        if (it->getName() == name) {
            a = *it;
            owners.erase(it);
            a.addVehicle(vehicle);
            owners.insert(a);
            return true;
        }
    }
    return false;
}

vector<string> OwnerRecord::showOwners() {
    vector<string> v;
    for (Owner owner : owners)
        v.push_back("Name: " + owner.getName() + " - Number of Vehicles: " + to_string(owner.getNumVehicles()));
    return v;
}

bool OwnerRecord::deleteOwner(Owner o1) {
    if (owners.erase(o1))
        return true;
    return false;
}

Owner OwnerRecord::getOwner(int index) {
    auto it = owners.begin();
    while (!(!index)) {
        it++;
        index--;
    }
    return *it;
}

bool OwnerRecord::checkPlate(string plate) {
    for (Owner owner: owners)
        for (Vehicle* v: owner.getVehicles())
            if (v->getPlate() == plate)
                return true;
    return false;
}