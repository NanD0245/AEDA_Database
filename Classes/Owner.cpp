//
// Created by mim on 15/12/20.
//

#include "Owner.h"

Owner::Owner(string name) : name(name) {vehicles.clear(); }

string Owner::getName() const {return name; }

void Owner::setName(string name) {this->name = name; }

int Owner::getNumVehicles() const {return vehicles.size(); }

bool Owner::addVehicle(Vehicle *vehicle) {
    for (Vehicle* v : vehicles)
        if (*vehicle == *v)
            return false;
    vehicles.push_back(vehicle);
    return true;
}

bool Owner::addVehicle(string plate, int v_class, float tax) {
    for (Vehicle* v : vehicles)
        if (plate == v->getPlate())
            return false;
    vehicles.push_back(new Vehicle(plate,v_class,tax));
    return true;
}

bool Owner::deleteVehicle(string plate) {
    for (size_t i = 0; i < vehicles.size(); i++)
        if (vehicles[i]->getPlate() == plate) {
            vehicles.erase(vehicles.begin()+i);
            return true;
        }
    return false;
}

bool Owner::deleteVehicle(int index) {
    if (index >= vehicles.size() || index < 0)
        return false;
    if (vehicles.erase(vehicles.begin()+index) != vehicles.end())
        return true;
    return false;
}

bool Owner::operator==(const Owner& o1) {
    return name == o1.getName();
}

string Owner::getInfo() const{
    string s = name+" : ";
    for(auto vehicle : vehicles){
        s+=vehicle->getInfov2() + " ";
    }
    s.pop_back();
    return s;
}

vector<Vehicle*> Owner::getVehicles() {return vehicles; }

vector<string> Owner::showVehicles() {
    vector<string> s;
    for (Vehicle* v : vehicles)
        s.push_back(v->showVehicle());
    return s;
}