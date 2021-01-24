#include "Movement.h"

Movement::Movement(Vehicle *vehicle1, Highway *highway1, Toll *toll1, Lane *lane1, Date *date) : vehicle(vehicle1), highway(highway1), toll(toll1), lane(lane1), date(date) {
    type = false;
}

Date * Movement::getDate() const {return date;}

Highway * Movement::getHighway() const {return highway;}

Lane * Movement::getLane() const {return lane;}

Toll * Movement::getToll() const {return toll;}

Vehicle * Movement::getVehicle() const {return vehicle;}

bool Movement::getType() const {return type;}

string Movement::getInfo() const {
    return date->getInfo() + " - " + highway->getInfo() + " - " + toll->getName()+ " - " + to_string(lane->getLaneNumber())+ " - " + vehicle->getPlate();
}

float Movement::getPrice() const {return -1;}

float Movement::getDistance() const {return -1;}

string Movement::showMovement() const {
    string s_type = type ? "Exit" : "Entrance";
    return date->getInfo() + " - Movement Type: " + s_type + " - Highway Name: " + highway->getInfo() +
           " - Toll Name: " + toll->getName() + " - Lane Number: " + to_string(lane->getLaneNumber()) + " - Vehicle Plate: " + vehicle->getPlate();
}



MovementEntry::MovementEntry(Vehicle *vehicle1, Highway *highway1, Toll *toll1, Lane *lane1, Date *date) : Movement(vehicle1,highway1,toll1,lane1, date) {
    type = false;
}

string MovementEntry::getInfo() const {
    return Movement::getInfo();
}

string MovementEntry::showMovement() const {
    return Movement::showMovement();
}



MovementOut::MovementOut(Vehicle *vehicle1, Highway *highway1, Toll *toll1, Lane *lane1, Date * date,
                         Movement *entry) : Movement(vehicle1,highway1,toll1,lane1, date), entry(entry) {
    type = true;
    this->distance = abs(toll1->getKilometer() - entry->getToll()->getKilometer());
    this->price = abs(distance*vehicle1->getTax());
}

MovementOut::MovementOut(Vehicle *vehicle1, Highway *highway1, Toll *toll1, Lane *lane1, Date *date, Movement *entry, float price) : Movement(vehicle1,highway1,toll1,lane1, date), entry(entry) {
    type = true;
    this->price = price;
    this->distance = abs(toll1->getKilometer() - entry->getToll()->getKilometer());
}

float MovementOut::getDistance() const {return distance;}

float MovementOut::getPrice() const {return price;}

string MovementOut::getInfo() const {
    return Movement::getInfo() + " - " + to_string(distance) + " - " + to_string(price) + " - " + entry->getInfo();
}

string MovementOut::showMovement() const {
    return Movement::showMovement() + " - Distance: " + to_string(distance) + " - Price: " + to_string(price) + "\n\t\t" + "Entry Movement: " + entry->showMovement();
}