#include "VehicleRecord.h"

using namespace std;

VehicleRecord::VehicleRecord() {
    vehicles.clear();
    for (int i = 0; i < 4; i++) {
        taxes[i] = -1;
    }
}

int VehicleRecord::getNumVehicles() const {return vehicles.size();}

float VehicleRecord::getTaxes(int v_class) {return taxes[v_class-1];}

Vehicle * VehicleRecord::getVehicle(string plate) {
    for (size_t i = 0; i < vehicles.size(); i++) {
        if (vehicles[i]->getPlate() == plate) {
            return vehicles[i];
        }
    }
    return nullptr;
}

Vehicle * VehicleRecord::getVehicleIndex(int i) {
    if (i < vehicles.size())
        return vehicles[i];
    return nullptr;
}

void VehicleRecord::setTaxes(float a, float b, float c, float d) {
    taxes[0] = a;
    taxes[1] = b;
    taxes[2] = c;
    taxes[3] = d;
}

bool VehicleRecord::checkPlate(string plate) {
    for (size_t i = 0; i < vehicles.size(); i++) {
        if (vehicles[i]->getPlate() == plate)
            return true;
    }
    return false;
}

bool VehicleRecord::addVehicle(string plate, int v_class) {
    for (size_t i = 0; i < vehicles.size(); i++) {
        if (vehicles[i]->getPlate() == plate) {
            cout << "Existe um veiculo com a mesma matricula" << endl;
            return false;
        }
    }
    auto * a1 = new Vehicle(plate,v_class,taxes[v_class-1]);
    vehicles.push_back(a1);
    return true;
}

bool VehicleRecord::addVehicle(string plate, int v_class, bool greenlane) {
    if (addVehicle(plate,v_class)) {
        vehicles[vehicles.size()-1]->defineLaneType(greenlane);
        return true;
    }
    return false;
}

bool VehicleRecord::removeVehicle(int i) {
    if (i >= vehicles.size())
        return false;
    vehicles.erase(vehicles.begin()+i);
    return true;
}
