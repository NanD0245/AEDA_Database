#include "Highway.h"

using namespace std;

Highway::Highway(string name) : name(name) { tolls.clear(); }

int Highway::getNumTolls() const {return tolls.size();}

Toll * Highway::getToll(string name) {
    for (size_t i = 0; i < tolls.size(); i++) {
        if (name == tolls[i]->getName())
            return tolls[i];
    }
    return nullptr;
}

Toll * Highway::getTollIndex(int i) {
    if (i < getNumTolls())
        return tolls[i];
    return nullptr;
}

string Highway::getInfo() const { return name; }

string Highway::showHighway() const {
    return "Highway Name: " + name;
}

void Highway::setName(const string new_name) { name = new_name; }

bool Highway::addToll(string name, string geolocal, float highway_kilometer,bool type) {
    if (!type) {
        Toll *t1 = new TollEntrance(name, geolocal, highway_kilometer);
        for (size_t i = 0; i < tolls.size(); i++) {
            if (tolls[i]->getInfo() == t1->getInfo()) {
                return false;
            }
        }
        tolls.push_back(t1);
    }
    else {
        Toll *t1 = new TollOut(name, geolocal, highway_kilometer);
        for (size_t i = 0; i < tolls.size(); i++) {
            if (tolls[i]->getInfo() == t1->getInfo()) {
                return false;
            }
        }
        tolls.push_back(t1);
    }
    return true;
}

bool Highway::addToll(Toll *t){
    tolls.push_back(t);
    return true;
}

bool Highway::removeToll(Toll *t1) {
    for (size_t i = 0; i < tolls.size(); i++) {
        if (*tolls[i] == *t1) {
            tolls.erase(tolls.begin()+i);
            return true;
        }
    }
    return false;
}

bool Highway::removeToll(int i) {
    if (i >= tolls.size())
        return false;
    tolls.erase(tolls.begin()+i);
    return true;
}

bool Highway::checkTollName(string name) {
    for (size_t i = 0; i < tolls.size(); i++) {
        if (name == tolls[i]->getName())
            return true;
    }
    return false;
}

bool Highway::operator==(const Highway &l2) { return name == l2.getInfo(); }

bool Highway::checkTechnicianName(string name) {
    for (Toll* t : tolls) {
        if (!t->checkTechnicianName(name))
            return false;
    }
    return true;
}

vector<Toll *> Highway::sortTollDistance(Toll* toll) {
    vector<Toll *> t;
    vector<Toll *> t_copy = tolls;
    while (!t_copy.empty()) {
        int index = 0;
        for (size_t i = 0; i < t_copy.size(); i++) {
            float f1 = toll->getKilometer() - t_copy[i]->getKilometer();
            if(f1 <0){
                f1=-f1;
            }
            float f2= toll->getKilometer() - t_copy[index]->getKilometer();
            if(f2 <0){
                f2=-f2;
            }
            if (f1<f2)
                index = i;
        }
        t.push_back(t_copy[index]);
        t_copy.erase(t_copy.begin() + index);
    }
    return t;
}

Technician * Highway::getTechnicianName(string name) {
    for (size_t i = 0; i < tolls.size(); i++) {
        Technician* tech = tolls[i]->getTechnicianName(name);
        if (tech != nullptr)
            return tech;
    }
    return nullptr;
}