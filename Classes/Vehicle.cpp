#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(string plate, int v_class, float tax): plate(plate), v_class(v_class), tax(tax) {}

void Vehicle::defineLaneType(bool greenlane){this->greenlane=greenlane;}

string Vehicle::getPlate() const {return plate;}

bool Vehicle::getGreenLaneBool() const {return greenlane;}

int Vehicle::getClass() const {return v_class;}

float Vehicle::getTax() const {return tax;}

string Vehicle::getInfo() const {
    return plate + " - " + to_string(v_class) + " - " + to_string(greenlane);
}

string Vehicle::getInfov2() const {
    return plate + " " + to_string(v_class) + " " + to_string(greenlane);
}

string Vehicle::showVehicle() const {
    string s_greenlane;
    s_greenlane = greenlane ? "True" : "False";
    return "Plate: " + plate + " - Classe: " + to_string(v_class) + " - Greenlane: " + s_greenlane;
}

void Vehicle::setGreenLaneTrue() {greenlane = true;}

void Vehicle::setGreenLaneFalse() {greenlane = false;}

void Vehicle::setVehicleClass(int v_class) {this->v_class = v_class;}

void Vehicle::setPlate(string plate) {this->plate = plate;}

void Vehicle::setTax(float tax) {this->tax = tax;}

bool Vehicle::operator==(Vehicle v1) {
    return plate == v1.getPlate();
}
